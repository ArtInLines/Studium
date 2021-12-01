;;;; Given an integer array nums, return all the triplets `[nums[i], nums[j], nums[k]]` such that `i != j`, `i != k`, and `j != k`, and `nums[i] + nums[j] + nums[k] == 0`.

(defun conc(L1 L2)
    (cond ((null L1) L2)
          (T (cons (car L1) (conc (cdr L1) L2)))))

(defun includesAtom (L E)
    (cond ((null L) nil)
          ((= E (car L)) T)
          (T (includes (cdr L) E))))
          
(defun includes (L E)
    (cond ((atom E) (includesAtom L E))
          ((null L) nil)
          ((equal E (car L)) T)
          (T (includes (cdr L) E))))

(defun findSummand (X L)
    (cond ((null L) nil)
          ((= 0 (+ X (car L))) (car L))
          (T (findSummand X (cdr L)))))

;;; DEBUG:
(defun rmDuplicates (L)
    (cond ((null L) L)
          ((null (includes L (car L))) (append (list (car L)) (rmDuplicates (cdr L))))
          (T (rmDuplicates (cdr L)))))

(defun 3SumHelper (L)
    (conc (3Sum (cons (car L) (cddr L)))  (3Sum (cdr L))))
    
(defun getSummand (L)
    (findSummand (+ (car L) (cadr L)) (cddr L)))

;;; TODO: Once, rmDuplicates is fixed, at it in here
(defun 3Sum (L)
    (cond ((null (cddr L)) nil) ; Less than 3 elements
          ((null (getSummand L))   (3SumHelper L))
          (T  (cons (list (car L) (cadr L) (getSummand L)) (3SumHelper L)))
    )
)