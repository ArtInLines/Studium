const { spawn } = require('node:child_process');
const process = require('process');
const fs = require('fs');
const path = require('path');

const tmpPath = path.join(__dirname, 'tmp');
if (!fs.existsSync(tmpPath)) fs.mkdirSync(tmpPath);
const procs = {};

function showProcesses() {
	let toExit = true;
	console.clear();
	// See: https://stackoverflow.com/a/41407246/13764271
	for (const id of Object.keys(procs)) {
		if (procs[id].active) {
			console.log('\x1b[32m%s\x1b[0m', "Process '" + id + "' running");
			toExit = false;
		} else console.log('\x1b[31m%s\x1b[0m', "Process '" + id + "' closed");
	}
	if (toExit) process.exit();
}

function saveProcWord(id) {
	fs.writeFileSync(path.join(tmpPath, id + '.txt'), procs[id].word);
}

function addProcess(id, word) {
	const p = spawn('node', ['duden2.js', id, word], { stdio: ['pipe', 'pipe', 'pipe', 'ipc'] });

	p.on('spawn', () => {
		procs[id] = { active: true, word, proc: p };
	});

	p.on('close', (code) => {
		console.log('Process ' + id + ' closing with code ' + code);
		procs[id].active = false;
		saveProcWord(id);
		showProcesses();
	});

	p.on('message', (msg) => {
		procs[id].word = msg;
	});

	p.stdout.on('data', (chunk) => {
		console.log(chunk.toString());
	});

	p.on('error', (err) => {
		saveProcWord(id);
		console.log('\x1b[31m%s\x1b[0m', 'Error on process: ' + id);
		console.log(err);
		process.exit();
	});
}

process.on('SIGINT', () => {
	console.log('Ended by CTRL+C');
	process.exit(0);
});

process.on('exit', () => {
	console.log('Exiting...');
	for (const id of Object.keys(procs)) {
		saveProcWord(id);
	}
});

process.stdin.resume();

let tmpFiles = fs
	.readdirSync(tmpPath, { withFileTypes: true })
	.filter((dirent) => dirent.isFile())
	.map((dirent) => dirent.name.split('.txt')[0]);
for (let id of tmpFiles) {
	let fpath = path.join(tmpPath, id + '.txt');
	if (!fs.existsSync(fpath)) {
		console.log('\x1b[31m%s\x1b[0m', 'Temporary File for id ' + id + " wasn't found");
		process.exit();
	}
	let word = fs.readFileSync(fpath, { encoding: 'utf-8' });
	addProcess(id, word);
}
showProcesses();
