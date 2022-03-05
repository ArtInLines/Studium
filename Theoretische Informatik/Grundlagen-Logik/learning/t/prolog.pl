% Für Rekursion muss gegeben sein:
% 1. Input muss echt kleiner sein als davor
% 2. Einen Abbruchfall geben, der irgendwann erreicht wird.

% Beispiel fibonacci
fib(0, 0).
fib(1, 1).
% fib(N, Y+Z) :- N>1, fib(N-1, Y), fib(N-2, Z).
fib(N, X) :- N>1, EINS is N-1, ZWEI is N-2, fib(EINS, Y), fib(ZWEI, Z), X is Y+Z.


max(X1, X2, X1) :- X1 > X2.
max(X1, X2, X2) :- X2 >= X1.

% Betrag von x
% Falls x positiv ist, gib x zurück.
% Falls x negativ ist, gib den Betrag von x zurück.

betrag(X, X) :- X >= 0.
betrag(X, Z) :- X < 0, Z is X * -1.

% f
% Berechne x * y, falls beide positiv / negativ sind
% Berechne x * y * -1, falls eine der Zahlen negativ & die andere positiv ist.

f(X, Y, Z) :- X>=0, Y>=0, Z is X*Y.
f(X, Y, Z) :- X<0, Y<0, Z is X*Y.
f(X, Y, Z) :- X<0, Y>=0, Z is X*Y*(-1).
f(X, Y, Z) :- X>=0, Y<0, Z is X*Y*(-1).


% [X | Rest]

% [1, 2, 3, 4]
% X = 1
% Rest = [2, 3, 4]

% [X, Y | Rest]
% X = 1
% Y = 2
% Rest = [3, 4]


% [X, Y | Rest]
% [1, 2]
% X = 1
% Y = 2
% Rest = []


% letzte
% Gib das letzte Element einer Liste zurück

letzte([], nil).
letzte([X], X).
letzte([X|Rest], Z) :- letzte(Rest, Z).

% So wird das ausgeführt
% letzte([1, 2, 3])
% X <-> 1
% Rest <- [2, 3]
% Z <- ?

% letzte([2, 3])
% X <-> 2
% Rest <- [3]
% Z <- ?

% letzte([3])
% X <-> 3



% conc
% Führt 2 Listen zu einer zusammen
% [1, 2, 3], [2, 3, 4] -> [1, 2, 3, 2, 3, 4]

conc([], [], []).
conc([X|Rest], [], [X|Rest]).
conc([], [X|Rest], [X|Rest]).
conc([X|R1], [Y|R2], [X|R3]) :- conc(R1, [Y|R2], R3).

Beispiel-Durchlauf
[1, 2], [2, 3, 4, 5] = [1, 2, 3, 4, 5] => [1 | [2, 2, 3, 4, 5]]
X = 1
R1 = [2]
Y = 2
R2 = [3, 4, 5]
conc([2], [2, 3, 4, 5], R3) => [2 | [2, 3, 4, 5]]
X = 2
R1 = []
Y = 2
R2 = [3, 4, 5]
conc([], [2, 3, 4, 5], R3) => [2, 3, 4, 5]




% Noch bessere Version von conc:
conc([],L,L).
conc([X|R], L, [X|RL]) :- conc(R, L, RL).


% conc([1, 2, 3], [2, 3, 4], Z).
% X <- 1
% R <- [2, 3]
% RL <- [2, 3, 2, 3, 4]
% Z <- [1|[2, 3, 2, 3, 4]] = [1, 2, 3, 2, 3, 4]

% conc([2, 3], [2, 3, 4], Z)
% X <-> 2
% R <- [3]
% RL <- [3, 2, 3, 4]
% Z <- [2|[3, 2, 3, 4]] = [2, 3, 2, 3, 4]

% conc([3], [2, 3, 4], Z)
% X <- 3
% R <- []
% RL <- [2, 3, 4]
% Z <- [3|[2, 3, 4]] = [3, 2, 3, 4]

% conc([], [2, 3, 4], Z)
% L <- [2, 3, 4]
% Z <- [2, 3, 4]



% rev
% Dreht die Liste um
% [1, 2, 3] -> [3, 2, 1]

rev([], []).
rev([X|Rest], Ergebnis) :- rev(Rest, Z), conc(Z, [X], Ergebnis).

% rev([1, 2, 3])
% X <-> 1
% Rest <- [2, 3]
% Z <- [3, 2]
% Ergebis <- [3, 2, 1]
% conc([3, 2], [1], Ergebnis) = [3, 2, 1]



% 16 10)
% Definiere eine Prolog Funktion die bei einer Liste alle 0 rausnimmt und alle negativen Zahlen mit -1 multipliziert
% Bsp.: [1, -1, 0, 2] => [1, 1, 2]

f([], []).
f([0|R], Z) :- f(R, Z).
f([X|R], [X|Z]) :- X>0, f(R, Z).
f([X|R], [Y|Z]) :- X<0, Y is X*(-1), f(R, Z).

f(Input, Output) :- Bedingungen & Funktionsaufrufe.