1. Rekursion
2. Listen

[1, 2, 3] = [X, Y, Z]
X = 1
Y = 2
Z = 3

[1, 2, 3] = [X | R]
X = 1
R = [2, 3]
[1 | [2, 3]]

[1 | [2, 3]] = [1, 2, 3]

[1 | [2, 3 | [4, 5]]] = [1, 2, 3, 4, 5]




p1([X|[Y|Y]],[]) = p1([A,A],A)

[X|[Y|Y]] = [A,A]

X <-> A <-> Y <-> [] <-> A



p2([Y|Y],[Y]) = p2([A,R],[R])

[Y|Y] = [A,R]
Y <-> A <-> [R] <-> R occur check!


Liste L
wenn L leer ist: 0
alle Elemente von L zusammen addieren, außer negative Zahlen, die werden dazumultipliziert

[1, 2, -3, 4, -1] => ((1 + 2) * (-3) + 4) * (-1)

f([], 0).
f([X|R], Z) :- X < 0, f(R, P), Z is X * P.
f([X|R], Z) :- X >= 0, f(R, P), Z is X + P.