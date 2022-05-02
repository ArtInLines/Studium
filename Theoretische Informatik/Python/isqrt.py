# Statt x // 4 kann auch x >> 2 geschrieben werden
# Statt r * 2 kann auch r << 1 geschrieben werden

def isqrt(x):
	if x < 4:
		return 1
	r = isqrt(x // 4)
	if (r * 2 + 1) ** 2 <= x:
		return r * 2 + 1
	else:
		return r * 2
