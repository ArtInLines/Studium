max(X, Y, Z) :- X > Y, Z is X.
max(X, Y, Z) :- Y >= X, Z is Y.

max(10, 11, Z).
    max(X, Y, Z) :- X > Y, Z is X.
    X = 10
    Y = 11
    Z = ?
    10 > 11 => Falsch

    max(X, Y, Z) :- Y >= X, Z is Y.
    X = 10
    Y = 11
    Z = ?
    11 >= 10 => Wahr
    Z = Y = 11 => Wahr
    . (Fertig)
Z = 11


max([], 0).
max([Head | [] ], Head).
max([Head | Restliste], X) :- max(Restliste, Z), Z >= Head, X is Z.
max([Head | Restliste], X) :- max(Restliste, Z), Head > Z, X is Head.

max([1, 2, 5], Ergebnis)
    max([], 0).
    
    max([Head | [] ], Head).
    
    max([Head | Restliste], X) :- max(Restliste, Z), Z >= Head, X is Z.
    Head = 1
    Restliste = [2, 5]
    X = ?
    max([2, 5], Z)
        max([], 0).
        
        max([Head | [] ], Head).
        
        max([Head | Restliste], X) :- max(Restliste, Z), Z >= Head, X is Z.
        Head = 2
        Restliste = [5]
        X = ?
        max([5], Z)
            max([], 0).
            
            max([Head | [] ], Head).
            Head = 5
        Z = 5
        Z >= Head  =>  5 >= 2  =>  Wahr
        X = Z = 5
    Z = 5
    Z >= Head  =>  5 >= 1  => Wahr
    X = Z = 5
Ergebnis = 5.


% [1, 2, 5]
% Ergebnis = 1
% [2, 5]
% 2 > 1 => Ergebnis = 2
% [5] => Ergebnis = 5

% max([], 0).
% max([Head], Head).
% max([Head | Restliste], Ergebnis) :- Head > Ergebnis, Ergebnis is Head, max(Restlliste, Ergebnis).
% max([Head | Restliste], Ergebnis) :- Head <= Ergebnis, max(Restlliste, Ergebnis).

% max([1, 2, 5], 0).



betrag(Liste) => Liste
    Falls die Liste leer ist: Leere Liste ausgeben
    Falls Erstes Element negativ: * -1
    Ansonsten so lassen
    betrag(Restliste)
    (Verändertes) erstes Element wieder an den Anfang der veränderten Restliste hängen

betrag([], []).
betrag([Head | Restliste], [NeuerHead | S]) :- Head < 0, NeuerHead is Head * -1, betrag(Restliste, S).
betrag([Head | Restliste], [Head | S]) :- Head >= 0, betrag(Restliste, S).

betrag([1, -4, -2], Ergebnis)
    betrag([Head | Restliste], [Head | S]) :- Head >= 0, betrag(Restliste, S).
    Head = 1
    Restliste = [-4, -2]
    1 >= 0  =>  Wahr
    betrag([-4, -2], S)
        betrag([Head | Restliste], [NeuerHead | S]) :- Head < 0, NeuerHead is Head * -1, betrag(Restliste, S).
        Head = -4
        Restliste = [-2]
        -2 < 0  =>  Wahr
        NeuerHead = 4
        betrag([-2], S)
            betrag([Head | Restliste], [NeuerHead | S]) :- Head < 0, NeuerHead is Head * -1, betrag(Restliste, S).
            Head = -2
            Restliste = []
            -2 < 0  =>  Wahr
            NeuerHead = 2
            betrag([], S)
                betrag([], []).
            S = []
            [NeuerHead | S]
            [2 | []] = [2]
        [NeuerHead | S]
        [4 | [2] ] = [4, 2]
    [Head | S]
    [1 | [4, 2]] = [1, 4, 2]
Ergebnis = [2, 4, 2]



L1 = [1, 2]
L2 = [5, 6, 7]
[...L1, ...L2]
conc(L1, L2) => Liste
    Falls L1 leer ist: => L2
    conc(Restliste von L1, L2) => [2, 5, 6, 7]
    Erstes Element von L1 an den Anfang der neuen Restliste schieben => [1, 2, 5, 6, 7]

conc([], L2, L2).
conc([Head | Restliste], L2, [Head | NeueListe]) :- conc(Restliste, L2, NeueListe).


conc([1, 2], [5, 6], L)
    conc([Head | Restliste], L2, [Head | NeueListe]) :- conc(Restliste, L2, NeueListe).
    Head = 1
    Restliste = [2]
    L2 = [5, 6]
    conc([2], [5, 6], NeueListe)
        conc([Head | Restliste], L2, [Head | NeueListe]) :- conc(Restliste, L2, NeueListe).
        Head = 2
        Restliste = []
        L2 = [5, 6]
        conc([], [5, 6], NeueListe)
            conc([], L2, L2).
            L2 = [5, 6]
        NeueListe = [5, 6]
        [Head | NeueListe]
        [2 | [5, 6]] = [2, 5, 6]
    NeueListe = [2, 5, 6]
    [Head | NeueListe]
    [1 | [2, 5, 6]] = [1, 2, 5, 6]
L = [1, 2, 5, 6]



oddpossum => Alle Zahlen auf ungeraden Position sollen zusammen addiert werden
oddpossum([], 0).
oddpossum([Head], Head).
oddpossum([Head, ZweitesElement | Restliste], Summe) :- oddpossum(Restliste, X), Summe is Head + X.

[1, 2, 3 | [4, 5, 6]]  =  [1, 2, 3, 4, 5, 6]

[Head, ZweitesElement | Restliste]  =  [1, 2, 3, 4, 5, 6]
Head = 1
ZweitesElement = 2
Restliste = [3, 4, 5, 6]


Aufgabe 8)

p1(X, [Y, X])  =  p1(A, [B, C])
X <-> A
Y <-> B
X <-> C <-> A

p2(X, [Y, Z])  =  p2([A, B], A)
X = [A, B]
A = [Y, Z]

X = [[Y, Z], B]

p3(X, [Y, X])  =  p2([A, B], A)
X = [A, B]
A = [Y, X]

X = [[Y, X], B]  =>  Occur Check!

p4([A, B, C | D], [A, B])  =  p4([X, Y], [X, Y])
X = A
Y = B
C = ?
Occur Check! Listen ungleich lang


Y = [B, C | D]
X = A
[A, B, C | D] =/= [A, [B, C | D]]

[1, 2, 3 | [4, 5]] = [1, 2, 3, 4, 5, 7]
[1, [2, 3 | [4, 5]]] = [1, [2, 3, 4, 5], 7]

1 =/= [1]



Occur Checks:
1. X = [X]  (Paradoxon)
2. [A, B] = [X]  (Ungleiche Länge)


16) Nr. 8)

p1( [ [X|Y] | [X,Y] ],  [ [Z] | X ])  =  p1([ A | [B|B] ],   C)
A = [X|Y]
B = X = [Y]
C = [ [Z] | X ]  =  [ [Z] | [Y] ]  =  [ [Z], Y ]


[1, 2, 3, 5] = [1 | [2, 3, 5]] = [1, 2 | [3, 5]]  =  [1, 2, 3, 5]

[1, 2, 3]  =  [A | B]
A = 1
B = [2, 3]

[X, Y]  =  [B | B]
B = X = [Y]



p2([Y|Y],[Y])  =  p2([A,R],[R])
A = Y
Y = [R]
[Y] = [R]

Y = [Y] Occur Check!


[1, 2] = [1 | [2]]
[ Head | Restliste ] = [A, R, S]
Head = A
Restliste = [R, S]

[P, Q, O] = [Head | Restliste]
P = Head
Restliste = [Q, O]


p3([ [] | [X|Y] ],  Y)  =  p3([A,Y1], Y1)
[] = A
[X | Y] = [Y1]
Y1 = X
Y = []
Y = Y1

Y = [] = Y1 = X = [] = A
[X | Y] = [Y1] = [[] | []] = [ [] ] = [ Y1 ]

=> Wahr / Occur Check

[X | []] = [X]



rev => Dreht die Liste um
[1, 2, 3] => [3, 2, 1]


rev([], []).
rev([Head | Restliste], L) :- rev(Restliste, Z), conc(Z, [Head], L).

[1]
Head = 1
rev([], Z).
Z = []
conc([], [1], L)
L = [1]

[1, 2, 3]
Restliste = [2, 3]
Z = [3, 2]
conc([3, 2], [1], L)
L = [3, 2, 1]
