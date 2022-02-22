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