const puppeteer = require('puppeteer');
const fs = require('fs');
const path = require('path');
const createCsvStringifier = require('csv-writer').createObjectCsvStringifier;

async function main() {
	const browser = await puppeteer.launch();
	const page = await browser.newPage();

	const dataDirPath = path.join(__dirname, 'data');
	if (!fs.existsSync(dataDirPath)) fs.mkdirSync(dataDirPath);

	const csvHeader = {
		header: [
			{ id: 'word', title: 'Wort' },
			{ id: 'type', title: 'Wortart' },
			{ id: 'frequency', title: 'Häufigkeit' },
			{ id: 'splitting', title: 'Worttrennung' },
			{ id: 'synonymlink', title: 'Link zu Synonymen' },
			{ id: 'grammarlink', title: 'Link zur Grammatik' },
		],
	};
	const csvStringifier = createCsvStringifier(csvHeader);
	let prevWord = 'Zoophobie';
	let letter = prevWord.slice(0, 2).toLowerCase();
	let stream = fs.createWriteStream(path.join(dataDirPath, `${letter}.csv`));

	stream.write(csvStringifier.getHeaderString());

	while (prevWord) {
		await page.goto(`https://www.duden.de/rechtschreibung/${prevWord}`);
		const mainArticleClass = '.tabloid__main-column';
		await page.waitForSelector(mainArticleClass);

		if (prevWord.slice(0, 2).toLowerCase() !== letter) {
			letter = prevWord.slice(0, 2).toLowerCase();
			stream.close();
			stream = fs.createWriteStream(path.join(dataDirPath, `${letter}.csv`));
			stream.write(csvStringifier.getHeaderString());
		}

		let word = (await page.$eval('.lemma__main', (el) => el.innerText)).split('­').join('');
		// console.assert(word.toLowerCase() === prevWord.toLowerCase(), `Wort ("${word}") und URLWort ("${prevWord}") sind nicht gleich`);
		let record = { word };
		let keys = await page.$$eval('.tuple__key', (els) => els.map((el) => el.innerText));
		let vals = await page.$$eval('.tuple__val', (els) => els.map((el) => el.innerText));
		keys.forEach((k, i) => {
			let key = k.toLowerCase();
			if (key.startsWith('wortart')) {
				record['type'] = vals[i].split(', ').join('|');
			} else if (key.startsWith('häufigkeit')) {
				let t = vals[i].split('\n');
				record['frequency'] = Math.floor((100 * t[0].length) / t[1].length) / 100;
			} else if (key.includes('trennung')) {
				record['splitting'] = vals[i];
			}
		});
		let links = await page.$$eval('.more__link', (els) => els.filter((el) => el.id));
		links.forEach((link, i) => {
			switch (link.id) {
				case 'synonyme':
					record['synonymlink'] = link.getAttribute('href');
					break;

				case 'grammatik':
					record['grammarlink'] = link.getAttribute('href');
					break;
			}
		});
		let str = csvStringifier.stringifyRecords([record]);

		console.log(str);
		stream.write(str);
		prevWord = await (await (await page.$('.hookup__group')).$$('.hookup__item')).pop().$eval('.hookup__link', (el) => el.getAttribute('href').split('/').pop());
	}

	if (!stream.closed) stream.close();
	await browser.close();
}

main();
