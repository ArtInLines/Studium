;;; Concatenate two lists
(defun conc(L1 L2)
    (cond ((null L1) L2)
          (T (cons (car L1) (conc (cdr L1) L2)))))

;;; Get a sublist containing all elements <= E
(defun splitk (L E)
    (cond ((null L) L)
          ((<= (car L) E) (cons (car L) (splitk (cdr L) E)))
          (T (splitk (cdr L) E))))

;;; Get a sublist containing all elements > E
(defun splitg (L E)
    (cond ((null L) L)
          ((> (car L) E) (cons (car L) (splitg (cdr L) E)))
          (T (splitg (cdr L) E))))
          
;;; Split a list into two sublists, containing all elements of L that are smaller or equal / bigger than E
(defun split (L E)
    (list (splitk L E) (splitg L E)))

;;; Implementation of QuickSort    
(defun qSort (L)
    (cond ((null L) L)
            (T (conc (qSort (splitk (cdr L) (car L))) (cons (car L) (qSort (splitg (cdr L) (car L))))))))

;;; Half a list into two equally sized sublists
(defun half (L)
    (cond ((null L) (list nil nil))
          ((null (cdr L)) (list L nil))
          (T (list 
                (cons (car L) (car (half (cddr L)))) 
                (cons (cadr L) (cadr (half (cddr L))))
            ))))

;;; Merge two sorted lists into a single sorted list
(defun mrg (L1 L2)
    (cond ((null L1) L2)
          ((null L2) L1)
          ((<= (car L1) (car L2)) (cons (car L1) (mrg (cdr L1) L2)))
          (T (cons (car L2) (mrg L1 (cdr L2))))
          ))

;;; Implementation of MergeSort
(defun mSort (L)
    (cond ((null L) L)
          ((null (cdr L)) L)
          (T (mrg (mSort (car (half L))) (mSort (cadr (half L)))))))

;;; Sum all elements at odd positions in the list (starting count at 1)
(defun oddpossum (L)
    (cond ((null L) 0)
          ((null (cadr L)) (car L))
          (T (+ (car L) (oddpossum (cddr L))))))

;;; Remove all 0s and replace all negative numbers in a list with their doubled absolute value
(defun onlypos (L)
    (cond ((null L) L)
          ((= 0 (car L)) (onlypos (cdr L)))
          ((> 0 (car L)) (cons (* -2 (car L)) (onlypos (cdr L))))
          (T (cons (car L) (onlypos (cdr L))))))

;;; Reverses the List          
(defun rev (L)
    (cond ((null L) L)
          (T (conc (rev (cdr L)) (list (car L))))))

;;; Returns T if the List L contains the Element E and NIL otherwise
(defun includes (L E)
    (cond ((null L) nil)
          ((= E (car L)) T)
          (T (includes (cdr L) E))))

;;; Joins two Lists zipper-wise
(defun zipper (L1 L2)
    (cond ((null L1) L2)
          ((null L2) L1)
          (T (cons (car L1) (cons (car L2) (zipper (cdr L1) (cdr L2)))))))