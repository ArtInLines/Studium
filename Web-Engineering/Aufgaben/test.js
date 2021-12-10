console.log(navigator.userAgent);

const root = document.getElementById('root');

function toStr(obj, indent = 0, startIndent = false) {
	let test = false;
	let str = (startIndent ? addIndent(indent) : '') + '{\n';
	for (const key in obj) {
		test = true;
		str += addIndent(indent + 1);
		let el = obj[key];
		if (Array.isArray(el)) el = '[' + el.map((val) => (typeof val === 'object' || typeof val === 'function' ? toStr(val, indent + 1) : val)).join(', ') + ']';
		else if (typeof el === 'object') {
			if (el === null) el = 'null';
			else el = el.constructor.name + ' ' + toStr(el, indent + 1);
		} else if (typeof el === 'function') el = `${el.name}()`;
		str += key + ': ' + el;
		str += '\n';
	}
	if (!test) return '{}';
	str += addIndent(indent) + '}';
	return str;
}

function addIndent(indent) {
	let s = '';
	for (let i = 0; i < indent; i++) s += '\t';
	return s;
}

const str = toStr(navigator);
str.split('\n').forEach((s) => {
	const line = document.createElement('p');
	s = s.split('\t');
	line.style.paddingLeft = 20 * (s.length - 1) + 'px';
	line.innerText = s[s.length - 1];
	root.insertAdjacentElement('beforeend', line);
});
