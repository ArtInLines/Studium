L = (1 2 3)

(car L) = 1
(cdr L) = (2 3)
(car (cdr L)) = 2 = (cadr L)


(+ 13 (car L)) = 14

(defun max (x y)
    (cond ((>= x y) x)
          (t y)))
       
Die Summe aller Elemente in der Liste   
(defun sum(L)
    (cond ((null L) 0)
          (t (+ (car L) (sum (cdr L))))))
          
; Reverse the list
(defun rev(L)
    (cond ((null L) nil)
          (t (append (rev (cdr L)) (list (car L))))))
          

(defun mystery (L)
    (cond ((listp L) (cond ((null L) 0)
                        ((< (car L) 0) (- (mystery (cdr L)) (car L)))
                        ((> (car L) 0) (+ (mystery (cdr L)) (car L)))
                        (T (mystery (cdr L))))
           (T nil)))

F(0) = 2
F(n) = 5 + F(n-1)
F(n) = n*5 + 2


mystery([],0).
mystery([X],X).
mystery([A,B|R],N) :- mystery(R,M), N is M+A.

F(1) = 2
F(n) = 4 + F(n-2)
F(n) = 4(n-1)/2 + 2

F(1) = 2
F(3) = 6
F(5) = 10


mystery([], 0).
mystery([H|R], Z) :- H >= 0, mystery(R, P), Z is H + P.
mystery([H|R], Z) :- H < 0, mystery(R, P), Z is H - P.


(list 1) = (1)
(cons (1) '(2 3)) = ((1) 2 3)
(append '(2 3) 1) = (2 3 1)

null ist zum Abfragen
nil ist zum Ausgeben


L = ( (1 2 3) (4 5 6) (7 8 9) (10 11 12) )
cdr L = ( (4 5 6) (7 8 9) )
car (cdr L) = (4 5 6)
car (car (cdr L)) = 4 = caadr L


cons el liste => (el liste[0] liste[1] liste[2] ...)
list el => (el)

(cond ((> 0 (caadr L)) (cons (cadr L) (cons (car L) (cddr L)))) (t L))



calculates the sum of the first number of the first and the first number of the second sublist and inserts this into a
new sublist located in front of the remaining sublists

(cons (list (+ (caar L) (caadr L))) L)

(zipper (msort (car L)) (msort (...)))