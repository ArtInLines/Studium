# Linear Search

```Py
{ N of type Integer; A is a list of integers (A[1,length(A]) }
I := 1
while (A[I] =/= N) and (i <= length(A)) do:
    I := I + 1
if A[I] =/= N:
    I := -1
{ I = Index of N in A, or -1 if N is not in A }
```

## Proof for Iterations

1. Choose INV (loop invariant) and prove its correctness

INV = { A[1,I) doesn't include N }
(A[1,I) means the intervall from 0 up to, but not including I)

2. Prove INV ^ not(B) => N

((A[i] = N) or (i > length(A))) and { A[1,I) doesn't include N } => True

3. Prove that the loop will terminate
