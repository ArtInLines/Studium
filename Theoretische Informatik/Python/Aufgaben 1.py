def teiler(n: int):
	return { x for x in range(1, n+1) if n % x == 0 }

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
	return teiler(m) & teiler(n)

# for i in range(1, 20):
# 	for j in range(1, 20):
# 		print(i, j, gt(i, j))

def ggt(m: int, n: int):
	return max(gt(m, n))

# for i in range(1, 20):
# 	for j in range(1, 20):
# 		print(i, j, ggt(i, j))

def kgv(m: int, n: int):
	return m * n // ggt(m, n)

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
	return { m for k in range(len(M) + 1) for m in subsets(M, k) }

# print(power({1, 2, 3}))

def pythagoras(n: int):
	return {(a, b, c) for c in range(5, n+1) for b in range(2, c) for a in range(1, b) if a**2 + b**2 == c**2}

# print(pythagoras(100))

def reducedPythagoras(n: int):
	return {(a, b, c) for (a, b, c) in pythagoras(n) if ggt(a, b) == 1}

# print(reducedPythagoras(50))

# Diese sind falsch!!
# Siehe Lsg. von Herrn Stroetmann
def aufgabe6A():
	return  3 * ((11 / 50) * (10 / 49) * (10 / 48)) + ((11 / 50) * (10 / 49) * (9 / 48))
def aufgabe6B():
	return (11 / 50) * (10 / 49) * (9 / 48)

# print(str(round(aufgabe6A() * 100, 4)) + "%")
# print(str(round(aufgabe6B() * 100, 4)) + "%")

def anagram(s: str):
	if s == "":
		return {s}
	return { s1[:i] + s[0] + s1[i:] for i in range(len(s)) for s1 in anagram(s[1:]) }

# Initial idea before Stroetmann told us of the other one	
# def anagram2(s: str):
# 	if s == '':
# 		return {s}
# 	return { s[i] + s1 for i in range(len(s)) for s1 in anagram(s[:i] + s[i+1:]) }

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

def diceRolls(n: int, s: int):
	if n == 0 or s == 0:
		return {}
	if n == 1 and 1 <= s <= 6:
		return {(s,)}
	return { t + (i,) for i in range(1, 6+1) for t in diceRolls(n-1, s-i) if len(t) > 0 }

# print(diceRolls(3, 5))