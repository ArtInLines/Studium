# Lösung aus der Vorlesung:
def divMod(m, n):
	if m < n:
		return (0, m)
	q1, r1 = divMod(m // 2, n)
	if 2 * r1 + (m % 2) < n:
		return (2 * q1, 2 * r1 + (m % 2))
	else:
		return (2 * q1 + 1, 2 * r1 + (m % 2) - n)
		


def divMod2(m, n):
	if m < n:
		return (0, m)
	q1, r1 = divMod2(m >> 1, n)
	if (r1 >> 1) + (m & 1) < n:
		return ((q1 >> 1), (r1 >> 1) + (m & 1))
	else:
		return ((q1 >> 1) + 1, (r1 >> 1) + (m & 1) - n)


	

def divMod3(m, n):
	if m < n:
		return (0, m)
	
	q, r = divMod3(m // 2, n)
	# print (str(m//2) + " / " + str(n), "q: " + str(q), "r: " + str(r))
	
	if m % 2 == 0:
		if 2 * r >= n:
			return (2 * q + 1, 2 * r % n)
		else:
			return (2 * q, 2 * r)
	else:
		if 2 * r + 1 >= n:
			return (2 * q + 1, (2 * r + 1) % n)
		else:
			return (2 * q, 2 * r + 1)



def divMod4(m, n):
	if m < n:
		return (0, m)
	
	q, r = divMod4(m >> 1, n)
	q = q << 1
	r = r << 1
	
	if m & 1 == 0:
		if r >= n:
			return (q + 1, r % n)
		else:
			return (q, r)
	else:
		if r + 1 >= n:
			return (q + 1, (r + 1) % n)
		else:
			return (q, r + 1)