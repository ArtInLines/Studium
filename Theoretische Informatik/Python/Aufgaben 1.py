def echteTeiler(n: int):
	return { x for x in range(1, n) if n % x == 0 }
	
# for i in range(1, 100):
# 	print(i, echteTeiler(i))

def isPerfect(n: int):
	return n == sum(echteTeiler(n))
	
# for i in range(2, 100):
# 	print(i, isPerfect(i))

# allePerfekten = { x for x in range(1, 10000) if isPerfect(x) }
# print(allePerfekten)

def gt(m: int, n: int):
	return echteTeiler(m) & echteTeiler(n)

def gt(a, b, c):
	return echteTeiler(a) & echteTeiler(b) & echteTeiler(c)

# for i in range(1, 20):
# 	for j in range(1, 20):
# 		print(i, j, gt(i, j))

def ggt(m: int, n: int):
	x = gt(m, n)
	if len(x) == 0:
		return 0
	return max(x)

# for i in range(1, 20):
# 	for j in range(1, 20):
# 		print(i, j, ggt(i, j))

def kgv(m: int, n: int):
	g = ggt(m, n)
	if g == 0:
		return m * n
	return int(abs((m / g) * n))

# for i in range(1, 20):
# 	for j in range(1, 20):
# 		print(i, j, kgv(i, j))

# Annahme: k <= |M|
def subsets(M, k):
	if k == 0:
		return {frozenset()}
	return { N | {x} for x in M for N in subsets(M - {x}, k-1) }

# print(subsets({1, 2, 3}, 2))

def power(M):
	res = set()
	for k in range(len(M) + 1):
		res = res | subsets(M, k)
	return res

# print(power({1, 2, 3}))

def pythagoras(n: int):
	return [(a, b, c) for c in range(5, n+1) for b in range(2, c) for a in range(1, b) if a**2 + b**2 == c**2]

# print(pythagoras(100))

def isReduced(a: int, b: int, c: int):
	return len(gt(a, b, c)) <= 1

def reducedPythagoras(n: int):
	return [(a, b, c) for (a, b, c) in pythagoras(n) if isReduced(a, b, c)]

# print(reducedPythagoras(50))

def aufgabe6A():
	return  3 * ((11 / 50) * (10 / 49) * (10 / 48)) + ((11 / 50) * (10 / 49) * (9 / 48))
def aufgabe6B():
	return (11 / 50) * (10 / 49) * (9 / 48)

# print(str(round(aufgabe6B() * 100, 2)) + "%")

def anagram(s: str):
	if s == "":
		return {""}
	return { s1[:i] + s[0] + s1[i:] for i in range(len(s)) for s1 in anagram(s[1:]) }

# print(anagram("abc"))

def numberDiceRolls(n: int, s: int):
	if n == 0 or s == 0:
		return 0
	if n == 1 and 1 <= s <= 6:
		return 1
	res = 0
	for i in range(1, 6+1):
		res += numberDiceRolls(n-1, s-i)
	return res

# print(numberDiceRolls(3, 5))