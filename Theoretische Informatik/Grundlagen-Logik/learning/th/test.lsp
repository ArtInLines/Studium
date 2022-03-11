; (func 1 2 3 ) = in C: func(1, 2, 3)

; 1 + 2 => (+ 1 2)

; X > 0 => (> X 0)

; '(1 2 3 4) => [1, 2, 3, 4]

; '(X Y Z) dann sieht es die als Liste [X, Y, Z] und nicht X(Y, Z)
; nicht wichtig innerhalb der Funktion

(defun max (X Y)
    ; if X >= Y then X
    ; else Y
    (cond ((>= X Y) X)
          (T Y)
    )
    ; cond ist quasi switch-case    
    ; case (X >= Y) X
    ; case (Y > X bzw. true) Y
)

; Betrag von x
; Falls x positiv ist, gib x zurück.
; Falls x negativ ist, gib den Betrag von x zurück.

(defun betrag (X)
    (cond ((> X 0) X)
          (T (* -1 X))))
          

; f
; Berechne x * y, falls beide positiv / negativ sind
; Berechne x * y * -1, falls eine der Zahlen negativ & die andere positiv ist.

(defun f (X Y)
    (cond ((or (and (> X 0) (> Y 0)) (and (< X 0) (< Y 0))) (* X Y))
          (T (* -1 X Y))))

; conc
; Führt 2 Listen zu einer zusammen
; (conc '(1 2 3) '(2 3 4)) -> (1 2 3 2 3 4)

(defun conc (L1 L2)
    (cond ((null L1) L2)
          ((null L2) L1)
          (T (cons (car L1) (conc (cdr L1) L2)))))
; (conc '(1 2 3) '(2 3 4))


; rev
; Dreht die Liste um
; [1, 2, 3] -> [3, 2, 1]

(defun rev (L)
    (cond ((null L) L)
          (T (append (rev (cdr L)) (car L) ))))


; 16 10)
; Definiere eine Lisp Funktion die bei einer Liste alle 0 rausnimmt und alle negativen Zahlen mit -1 multipliziert
; Bsp.: (1 -1 0 2) => (1 1 2)

(defun f (L) 
    (cond ((null L) L)
          ((= 0 (car L)) (f (cdr L)))
          ((> 0 (car L)) (cons (car L) (f (cdr L))))
          ((< 0 (car L)) (cons (* -1 (car L)) (f (cdr L))))))



; Gib T zurück, falls die Liste L das Element E enthält, ansonsten gib NIL zurück
; 1. Vergleiche das erste Element von L mit E
; 2. Falls gleich, dann gib T zurück
; 3. Andernfalls, gib Ergebnis des rekursiven Aufrufs zurück
; 4. Falls die Liste leer ist, gib NIL zurück

(defun includes (L E)
    (cond ((null L) nil)
          ((= (car L) E) T)
          (T (includes (cdr L) E))))



; oddpossum 
; Addiere alle Elemente einer Liste, die auf einer ungeraden Position sind, zusammen. (Liste startet mit Position 1)
; (oddpossum '(1 2 3 4)) => 4


(defun oddpossum (L)
    (cond ((null L) 0)
          ((null (cdr L)) (car L))
          (T (+ (car L) (oddpossum (cddr L)))))

1. Eingabewert: Liste
2. Leere Liste => 0
3. Leere Restliste => Erstes Element
4. Ansonsten => Erstes Element + oddpossum(Restliste der Restliste)

(-1 2 3 4 5) => -1 + 3 + 5 => 9

Summiert all Zahlen auf ungeraden Positionen

oddpossum([], 0).
oddpossum([X], X).
oddpossum([X,Y|R], P) :- oddpossum(R, Z), P is X + Z.


1. Rekursiven Aufruf
2. Base Case / Abbruchfall
3. Input muss kleiner werden


f([], []).
f([0|R], Z) :- f(R, Z).
f([X|R], [X|Z]) :- X>0, f(R, Z).
f([X|R], [Y|Z]) :- X<0, Y is X*(-1), f(R, Z).

1. Leere Liste => Leere Liste
2. Erstes Element = 0 => Rekursiver Aufruf mit R
3. Erstes Element > 0 => [X|Rekursiver Aufruf]
4. Erstes Element < 0 => [X*(-1)|Rekursiver Aufruf]

Wandelt alle negative in positive Zahlen um & löscht 0 aus der Liste

(defun f(L)
    (cond ((null L) L)
          ((= 0 (car L)) (f (cdr L)))
          ((> (car L) 0) (cons (car L) (f (cdr L))))
          ((< (car L) 0) (cons (* -1 (car L)) (f (cdr L))))))
          
          
          
mystery([],0).
mystery([X],X).
mystery([A,B|R],N) :- mystery(R,M), N is M+A


(defun mystery(L)
    (cond ((atom L) nil)
          ((null L) 0)
          ((null (cdr L)) (car L))
          (T (+ (mystery (cddr L)) (car L)))))


[-2, 0, 1, 2, 3, 4] => -2 + (1 + (3 + 0)) = 2  (oddpossum)
[-2, 0, 1, 2, 3, 4] => mystery([1, 2, 3, 4], 4), N is 4+(-2) => 2
[1, 2, 3, 4] => mystery([3, 4], 3), N is 3+1 => 4
[3, 4] => mystery([], 0), N is 0+3 => 3

Prolog
(Input, Output).
(Input, Output).

Lisp
((bedingung) (Output))


(defun mystery (L)
    (cond ((null L) L)
          ((atom L) nil) ; ignoriere diese Zeile
          ((null (cdr L)) nil)
          ((> (car L) (cadr L)) (cons (car L) (cons (cadr L) (mystery (cddr L)))))
          (T (mystery (cddr L))))

(cadr L) = (car (cdr L)) = Erste Element der Restliste = Zweite Element

mystery([], []).
mystery([X|[]], []).
mystery([X,Y|R], [X,Y|Z]) :- X>Y, mystery(R, Z).
mystery([X,Y|R], Z) :- mystery(R, Z).

[2, 3, 2, 1, 3] => [2, 1]


(defun mystery(L)
    (cond ((listp L)
            (cond ((null L) 0)
                  ((< (car L) 0) (- (mystery (cdr L)) (car L)))
                  ((> (car L) 0) (+ (mystery (cdr L)) (car L)))
                  (T (mystery (car L)))))
          (t nil)))
          
          
mystery([], 0).
mystery([X|R], Y) :- X<0, mystery(R, Z), Y is Z-X.
mystery([X|R], Y) :- X>0, mystery(R, Z), Y is Z+X.
mystery([X|R], Z) :- mystery(R, Z).



L = ((1 2 3) (2 3 4) (3 4 5)) 
((3 4 5)) = cddr L

=> ((1+2 1 2 3) (2 3 4) (3 4 5))
(cons (cons (+ (caar L) (caadr L)) (car L)) (cdr L))

reverses and exchanges the first two sublists if the list contains more than two sublists
=> ((4 3 2) (3 2 1) (3 4 5))
(cond ((null (cddr L)) L) (t (cons (rev (cadr L)) (cons (rev (car L)) (cddr L)))))

; Wichtige Standard-Funktionen in LISP

; list L1 L2 => (L1 L2)
; list '(1 2 3) '(2 3 4) => ((1 2 3) (2 3 4))
; list 1 2 => (1 2)

; cons E L => (E ...L)
; cons 3 '(1 2 3) => (3 1 2 3)
; cons '(1 2 3) '(2 3 4) => ((1 2 3) 2 3 4)

; append L E => (...L E)
; append '(1 2 3) 3 => (1 2 3 3)
; append '(1 2 3) '(2 3 4) => (1 2 3 (2 3 4))

; car L
; car '(1 2 3) => 1
; car '(1) => 1
; car '() => nil

; cdr L
; cdr '(1 2 3) => (2 3)
; cdr '(2 3) => (3)
; cdr '(3) => nil

; '(1 2 3)
; (car (cdr '(1 2 3 4))) => 2
; (cadr '(1 2 3 4)) => 2

; (cdr (car '((1 2 3) (2 3 4)))) => (2 3)
; cdar '((1 2 3) (2 3 4)) => (2 3)

; nil kannst du als Element verwenden
; (null L) checkt ob L die leere Liste ist