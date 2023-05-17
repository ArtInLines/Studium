document.addEventListener('keyup', (e) => {
	if (e.key === 'p') {
		print();
	}
});

function print() {
	const win = window.open('');
	win.document.write(html);
	win.print();
	win.close();
}
