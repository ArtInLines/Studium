;;;; Given an integer array nums, return all the triplets `[nums[i], nums[j], nums[k]]` such that `i != j`, `i != k`, and `j != k`, and `nums[i] + nums[j] + nums[k] == 0`.

(defun findSummand (X,L)
    (cond ((null L) nil)
          ((= 0 (+ X (car L))) (car L))
          (T (findSummand X (cdr L)))))


(defun 3Sum (L)
    (cond ((null (cddr L)) nil) ; Less than 3 elements in L
          (T (conc
             (findSummand (+ (car L) (cadr L)) (cddr L))
             (conc
                ()
             )
        ))
    ))