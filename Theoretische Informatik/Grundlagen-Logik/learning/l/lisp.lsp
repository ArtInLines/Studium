1. Rekursion
2. Listen

[X|R]

(1 2 3)

(car '(1 2 3))  (cdr '(1 2 3))

(> 2 3)

(defun name (Parameter1 Parameter2)
    (...))
    
(name Parameter1 Parameter2)


(defun conc (L1 L2)
    (cond ((null L1) L2)
          ((null L2) L1)
          (t (cons (car L1) (conc (cdr L1) L2)))))


(cons el liste) => (el liste[0] liste[1] liste[2] ...)


zipper(L1, L2, Ergebnis).
zipper([], L2, L2).
zipper(L1, [], L1).
zipper([X1|R1], [X2|R2], [X1 | [X2 | Z]]) :- zipper(R1, R2, Z).

(defun zipper (L1 L2)
    (cond ((null L1) L2)
          ((null L2) L1)
          (t ( cons (car L1) (cons (car L2) (zipper (cdr L1) (cdr L2)))))))
          
rev([], []).
rev([X|R], Z) :- rev(R, U), conc(U, [X], Z).

1. rev
2. conc

append liste el => (liste[0] ... liste[n] el)
          
(defun rev (L)
    (cond ((null L) L)
          (t (append (rev (cdr L)) (car L)))))


car
cdr
cons
append
list el => (el)
cond
defun


Define a Lisp function possum (analogous to Task 10) that calculates for a list of integer numbers the sum of all
positive numbers contained in it.
Example: (possum ‘(1 -8 0 -3 3)) returns 4

() => 0
(1 -2 3) => 4

(defun possum (L)
    (cond ((null L) 0)
          ((> (car L) 0) (+ (car L) (possum (cdr L))))
          ((>= 0 (car L)) (possum (cdr L)))))
          

possum([], []).
possum([X|R], Ergebnis) :- X>0, possum(R, Y), Ergebnis is X+Y.
possum([X|R], Y) :- X<=0, possum(R, Y).



L = ( (1 2 3) (2 3 4) (3 4 5) (4 5 6) )

replaces within the first sublist the first two numbers by the sum of these two numbers
=> ( (3 3) (2 3 4) (3 4 5) (4 5 6) )

(car (car L)) == (caar L)
1. Erste Element der ersten Subliste (caar L)
2. Zweite Element der ersten Subliste (cadar L)
3. Addiere die beiden Zahlen (+)
4. cons Summe (cddr L)
5. cons Subliste (cdr L)

(cons (cons (+ (cadar L) (caar L)) (cddr L)) (cdr L))


calculates the sum of the first number of the first sublist and the second number of the second sublist and inserts the result to the beginning of the second sublist
=> ( (1 2 3) (1+3 2 3 4) (3 4 5) (4 5 6) )

1. Erste Zahl der ersten Subliste (caar L)
2. Zweite Zahl der zweiten Subliste (cadadr L)
3. Addiere beide Zahlen (+)
4. cons Summe (cadr L)
5. cons Subliste (cddr L)
6. cons (car L) Restliste

(cons (car L) (cons (cons (+ (caar L) (cadadr L)) (cadr L)) (cddr L)))


deletes the first sublist and inserts the reverse of this first sublist to the end of L
L = ( (1 2 3) (2 3 4) (3 4 5) (4 5 6) ) => ( (2 3 4) (3 4 5) (4 5 6) (3 2 1) )

1. rev (car L)
2. append (cdr L) Subliste

(append (cdr L) (rev (car L)))



determines the length of the second sublist and inserts this to the end of the first sublist
=> ( (1 2 3 3) (2 3 4) (3 4 5) (4 5 6) )

1. length (cadr L)
2. append Länge (car L)
3. cons Subliste (cdr L)

(cons (append (length (cadr L)) (car L)) (cdr L))

