process.stdin.resume();

process.on('SIGINT', () => {
	console.log('bye bye');
	process.exit(0);
});
