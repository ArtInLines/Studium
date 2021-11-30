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
