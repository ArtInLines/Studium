const fs = require('fs');
const path = require('path');
const http = require('https');
const express = require('express');
const app = express();

app.use(express.json());

const PORT = process.env.PORT || 80;
const PAGE_SIZE = 100;
const DATA_FILE = path.join(__dirname, 'data.json');
const DATA_LIFETIME = 1000 * 60 * 60 * 15; // 15 days lifetime
let lastUpdated = null;
let notices = [];

// TODO:
// Sort the retrieved Data by entity_id
// Then respond with the current entity_id instead of the current cursor
// That way pagination should consist to work, even if the data changed

async function getJSONReq(url) {
	// Adapted from example in documentation here:
	// https://nodejs.org/api/http.html#httpgeturl-options-callback

	return new Promise((resolve, reject) => {
		http.get(url, (res) => {
			// Error Handling:
			const { statusCode, statusMessage } = res;
			const contentType = res.headers['content-type'];
			let err = null;
			// Check for error in response
			if (statusCode < 200 || statusCode >= 300) {
				err = new Error(`Status Code: ${statusCode}\nMessage: ${statusMessage}`);
			}
			// Check for correct content type
			else if (!/^application\/json/.test(contentType)) {
				err = new Error('Invalid content-type.\n' + `Expected application/json but received ${contentType}`);
			}
			// Handle Error
			if (err) {
				res.resume(); // Consume response data to free up memory
				reject(err);
			}

			// Stream data & returned parsed JSON
			res.setEncoding('utf8');
			let rawData = '';
			res.on('data', (chunk) => {
				rawData += chunk;
			});
			res.on('end', () => {
				try {
					resolve(JSON.parse(rawData));
				} catch (e) {
					reject(e);
				}
			});
		});
	});
}

async function getCountryCodes() {
	return new Promise((resolve, reject) => {
		try {
			const ccAPIUrl = 'https://restcountries.com/v3.1/all';
			getJSONReq(ccAPIUrl).then((res) => {
				resolve(res.map((x) => x['cca2']));
			});
		} catch (e) {
			reject(e);
		}
	});
}

async function getInterpolAPIData() {
	const countryCodes = await getCountryCodes();
	const notices = [];
	const noticesURL = 'https://ws-public.interpol.int/notices/v1/red';

	async function req(...keyArgs) {
		keyArgs = keyArgs.map((x) => String(x[0]) + '=' + String(x[1]));
		let url = noticesURL + '?' + keyArgs.join('&');
		return getJSONReq(url);
	}

	let age_args = [[0, 18]];
	for (let i = 0; i <= 60; i++) age_args.push([i, i]);
	age_args.push([60, 120]);

	for (const cc of countryCodes) {
		const country_arg = ['nationality', cc];
		const resPerPage_arg = ['resultsPerPage', 200];

		const resp = await req(country_arg, resPerPage_arg);
		// console.log(resp);
		let country_notices = resp._embedded.notices;
		if (country_notices.length < resp.total) {
			country_notices = [];
			for await (let id of ['F', 'M', 'U']) {
				let sd = await req(country_arg, resPerPage_arg, ['sexId', id]);
				if (sd.total > sd._embedded.notices.length) {
					for await (let age_arg of age_args) {
						let asd = await req(country_arg, resPerPage_arg, ['ageMin', age_arg[0]], ['ageMin', age_arg[1]]);
						country_notices.push(...asd._embedded.notices);
					}
				} else {
					country_notices.push(...sd._embedded.notices);
				}
			}
		}
		notices.push(...country_notices);
	}

	// Sort notices
	notices.sort((a, b) => a.entity_id - b.entity_id);
	// Remove duplicate notices
	for (let i = 0; i + 1 < notices.length; i++) {
		if (notices[i].entity_id == notices[i + 1].entity_id) {
			notices.splice(i + 1, 1);
			i--;
		}
	}

	return notices;
}

async function getData() {
	if (!fs.existsSync(DATA_FILE) || !lastUpdated || Date.now() > lastUpdated + DATA_LIFETIME) {
		notices = await getInterpolAPIData();
		return new Promise((resolve, reject) => {
			fs.writeFile(DATA_FILE, JSON.stringify(notices, null, 4), { encoding: 'utf-8' }, (err) => {
				if (err) reject(err);
				lastUpdated = Date.now();
				resolve(notices);
			});
		});
	} else return new Promise((resolve, reject) => resolve(notices));
}

app.get('/all', async (req, res) => {
	const data = await getData();
	const resData = { notices: data };
	res.send(resData);
}).get('/data', async (req, res) => {
	const cursor = Number(req.query?.page || 0);
	const data = await getData();
	const idx = PAGE_SIZE * cursor;
	const maxCursor = Math.floor(data.length / PAGE_SIZE);
	const nextCursor = cursor >= maxCursor ? maxCursor : cursor + 1;

	const resData = { max_cursor: maxCursor, notices: [], current_page: cursor, next_page: nextCursor };
	if (idx < data.length) resData.notices = data.slice(idx, idx + PAGE_SIZE);
	res.send(resData);
});

getData().then(() => {
	setInterval(() => {
		getData();
	}, DATA_LIFETIME);
});
app.listen(PORT, () => console.log(`Server listening on Port ${PORT}`));
