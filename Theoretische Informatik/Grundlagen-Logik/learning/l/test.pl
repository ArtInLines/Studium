BEI REKURSION GENERELL:

1. Muss sich selbst aufrufen
2. Input muss bei jedem Aufruf kleiner werden
3. Base-Case



BEISPIEL FÜR REKURSION

fakultät(n) {
    if (n <= 1) 1;
    n * fakultät(n-1);
}

fakultät(3) = 3 * 2 * 1
n = 3
fakultät(2) = 2 * 1
n = 2
fakultät(1) = 1


hier in Prolog:

fakultät(X, Ergebnis) :- X <= 1, Ergebnis is 1.
fakultät(X, Ergebnis) :- Y is X-1, fakultät(Y, Z), Ergebnis is X * Z.

":-" ist ein wenn-dann, das man von rechts nach links lesen muss:
if X <= 1 and if Ergebnis is 1 then fakultät(X, Ergebnis):




AUFGABE 8 - UNIFIZIEREN:

Beispiel für Listen & Restlisten:
[1, 2, 3] = [1 | [2, 3]]

[X | R] = [1, 2, 3]
X = 1
R = [2, 3]

[X, Y, Z | R] = [1, 2, 3]
X = 1
Y = 2
Z = 3
R = []

[X, Y, Z | R] = [1, 2]
Fehler
X = 1
Y = 2
Z = ?????


a) 
p1([[X|Y]|[X,Y]],[[Z]|X]) = p1([A|[B|B]],C)

Beispiel:
[1, 2, 3] = [1 | [2, 3]]
[ X | [X, Y] ] = [X, X, Y]
[1, 2, 3] = [X | R] = [1 | [2, 3]] = [X | [ Y | Z ]] = [1 | [2 | [3] ]]

A = 1
B = [2]
[A | [B | B]] = [1, [2], 2]

Lösung der Aufgabe:
[ [X|Y] | [X,Y] ] = [A | [B|B]]
// [ [X|Y], X, Y ] = [ A, B, B[0] ]

Das hier ist Hinzuschreiben:
A <- [X|Y] = [ [Y] | Y ]
B <-> X <- [Y]
[[Z]|X] -> C <- [[Z] | [Y]] = [ [Z], Y ]


b)
p2([[X|R]|Y],[Y|X]) = p2([Y1|A],[Y1])

[Y|X] = [Y1]
Y1 <-> Y
X <- []

[[X|R]|Y] = [Y1|A]

[X|R] -> Y1
Y <-> A

Das hier ist Hinzuschreiben:
Y1 <-> Y <-> A <-> [X|R] <-> [[] | R]


GENERELL FÜR AUFGABE 8:

Die beiden einzigen Arten von occur checks (ohne Gewähr):
- Y <-> [Y]
- [X, Y] = [A]



PROLOG FUNKTIONEN:

conc:
2 Listen zu einer Liste
[1, 2, 3], [2, 3, 4] -> [1, 2, 3, 2, 3, 4]

conc(L1, [], L1).
conc([], L2, L2).
conc([X | R], L2, [X | Z]) :- conc(R, L2, Z).



zipper:
2 Listen zu einer Liste (reisverschlussartig)
[1, 2, 3], [4, 5, 6, 7, 8] -> [1, 4, 2, 5, 3, 6, 7, 8]

zipper(L1, L2, Ergebnis).
zipper([], L2, L2).
zipper(L1, [], L1).
zipper([X1|R1], [X2|R2], [X1, X2 | Z]) :- zipper(R1, R2, Z).


L1 = [1, 2, 3], L2 =[4, 5, 6, 7, 8]
X1 = 1
X2 = 4
R1 = [2, 3]
R2 = [5, 6, 7, 8]
zipper(R1, R2, T) => Z = [1, 4, 2, 5, 3, 6, 7, 8]



rev:
Liste umdrehen
rev([1, 2, 3], [3, 2, 1])

rev([], []).
rev([X], [X]).
rev([X|R], Z) :- rev(R, U), conc(U, [X], Z).


rev([1, 2, 3], Ergebnis) = [3, 2, 1]
X = 1
R = [2, 3]
U = rev([2, 3], U) = [3, 2]
X = 2
R = [3]
U = rev([3], U) = [3]




TODO:

- Aufgabe 8
- conc, zipper, rev nochmal versuchen
