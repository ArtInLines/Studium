;;;; 4 semi-colons to describe program
;;; 3 semi-colons for comments
;; 2 semi-colons for indented comments
; 1 semi-colon for comments after a line of code

#|| 
Multiline Comment
||#

(format t "Hello World~%")

(defun conc(L1 L2)
    (cond ((null L1) L2)
          (T (cons (car L1) (conc (cdr L1) L2)))))

(defun splitk (L E)
    (cond ((null L) L)
          ((<= (car L) E) (cons (car L) (splitk (cdr L) E)))
          (T (splitk (cdr L) E))))

(defun splitg (L E)
    (cond ((null L) L)
          ((> (car L) E) (cons (car L) (splitg (cdr L) E)))
          (T (splitg (cdr L) E))))
          
(defun split (L E)
    (list (splitk L E) (splitg L E)))
    
(defun qSort (L)
    (cond ((null L) L)
            (T (conc (qSort (splitk (cdr L) (car L))) (cons (car L) (qSort (splitg (cdr L) (car L))))))))
            
(defun half (L)
    (cond ((null L) (list nil nil))
          ((null (cdr L)) (list L nil))
          (T (list 
                (cons (car L) (car (half (cddr L)))) 
                (cons (cadr L) (cadr (half (cddr L))))
            ))))

(defun mrg (L1 L2)
    (cond ((null L1) L2)
          ((null L2) L1)
          ((<= (car L1) (car L2)) (cons (car L1) (mrg (cdr L1) L2)))
          (T (cons (car L2) (mrg L1 (cdr L2))))
          ))
          
(defun mSort (L)
    (cond ((null L) L)
          ((null (cdr L)) L)
          (T (mrg (mSort (car (half L))) (mSort (cadr (half L)))))))