function t(x, y) {
	y = y - x;
	if (x < 0) {
		if (y < 0) y = x * y;
		else y = y - x;
	}

	return y < 0;
}

module.exports = t;
