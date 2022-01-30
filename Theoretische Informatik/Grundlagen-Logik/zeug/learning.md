$$
P \land Q \implies B = \neg (P \land Q) \lor B
$$

$$
\neg (P \land Q) \iff \neg P \lor \neg Q
$$

$$
\neg (P \lor Q) \iff \neg P \land \neg Q
$$

$$
(P \iff Q) \iff (P \rightarrow Q) \land (P \leftarrow Q) \iff (\neg P \lor Q) \land (\neg Q \lor P)
$$

$$
(P \iff Q) \iff (P \land Q) \lor (\neg P \land \neg Q)
$$

$$
(A \land B) \lor C \iff (A \lor C) \land (B \lor C)
$$

## CS 16

### 1)

-   $$
    natürlich(x) \land gerade(x) \rightarrow natürlich(x / 2)
    $$

-   $$
    natürlich(x) \land ungerade(x) \implies gerade(x + 1) \land gerade(x - 1)
    $$

-   $$
    natürlich(x) \implies gerade(x+1) \lor ungerade(x+1)
    $$

-   $$
    istQuadrat(x) \leftarrow natürlich(x) \land \exist y (natürlich(y) \land y*y = x)
    $$

## CS 17

### 1)

-   Der Nachfolger jeder natürlichen Quadratzahl ist eine natürliche Zahl:

$$
natürlich(x) \land quadrat(x) \implies natürlich(x+1)
$$

-   Das Ergebnis der Division einer geraden, natürlichen Zahl mit 2 ist eine natürliche Zahl:

$$
natürlich(x) \land gerade(x) \implies natürlich(x / 2)
$$

-   Jede natürliche Quadratzahl ist nicht negativ

$$
quadrat(x) \land natürlich(x) \implies \neg negativ(x)
$$

-   Die Summe des Vorgängers und des Nachfolgers einer Primzahl ist gerade

$$
primzahl(x) \implies gerade((x-1) + (x+1))
$$

## CS 16

### 3

$$
X = { R \lor (S \rightarrow Q), \neg R \iff \neg S, (\neg Q \lor S) \land \neg R }
$$

```
X:
\
  R = F -- S = F -- Q = W
```

$$ Y1: $$

$$ (\neg R \land S) \lor Q \implies P $$

$$ \neg ((\neg R \land S) \lor Q) \lor P $$

$$ ((R \lor \neg S) \land \neg Q ) \lor P $$

$$ (R \lor \neg S \lor P) \land (\neg Q \lor P) $$

$$ Y2: $$

$$ \neg \neg Q \implies \neg S $$

$$ Q \implies \neg S $$

$$ \neg Q \lor \neg S $$

$$ Y3: $$

$$ (R \implies \neg P) \lor Q $$

$$ \neg R \lor \neg P \lor Q $$

$$ Y = ((R \lor \neg S \lor P) \land (\neg Q \lor P)), (\neg Q \lor \neg S), (\neg R \lor \neg P \lor Q) $$

```
Y:
          Q = W - P = W - S = F
        /
  R = W                  S = W
/       \               /
          Q = F - P = F
                        \
                         S = F

          Q = W - P = W - S = F
\       /
  R = F                   P = W
        \               /
          Q = F - S = F
                        \
                          P = F
```

$$ Z1: $$

$$ Q \land \neg S \implies P $$

$$ \neg (Q \land \neg S) \lor P $$

$$ \neg Q \lor S \lor P $$

$$ Z2: $$

$$ \neg R \lor (\neg S \land \neg P \land Q) $$

$$ Z3: $$

$$ \neg P \lor S \implies Q $$

$$ \neg (\neg P \lor S) \lor Q $$

$$ (P \land \neg S) \lor Q $$

$$ Z: (\neg Q \lor S \lor P), (\neg R \lor (\neg S \land \neg P \land Q)), (P \land \neg S) \lor Q $$

```
Z:
                 S = W - R = F
               /
         P = W
       /       \
 Q = W           S = F - R = F
/      \
         P = F - S = W - R = F
\
 Q = F - P = W - S = F - R = F
```

X |= X

Y |= Y

Z |= Z

X |= Y

X |= Z

# CS 16

## 4)

### a)

$$ R \iff S \lor \neg Q \land P $$

$$ R \iff ((S \lor \neg Q) \land P) $$

$$ (\neg R \land \neg ((S \lor \neg Q) \land P)) \lor (R \land ((S \lor \neg Q) \land P)) $$

$$ (\neg R \lor (R \land (S \lor \neg Q) \land P)) \land (\neg ((S \lor \neg Q) \land P) \lor (R \land (S \lor \neg Q) \land P)) $$

$$ (\neg R \lor R) \land (\neg R \lor S \lor \neg Q) \land (\neg R \lor P) \land (\neg ((S \lor \neg Q) \land P) \lor (R \land (S \lor \neg Q) \land P)) $$

#

$$ (\neg S \land Q) \lor \neg P \lor (R \land (S \lor \neg Q) \land P)) $$

$$ ((\neg S \lor \neg P) \land (\neg P \lor Q)) \lor (R \land (S \lor \neg Q) \land P)) $$

$$ ((\neg S \lor \neg P \lor (R \land (S \lor \neg Q) \land P))) \land (\neg P \lor Q \lor (R \land (S \lor \neg Q) \land P)))) $$

$$ (\neg S \lor \neg P \lor (R \land (S \lor \neg Q) \land P)) $$

$$ ((\neg S \lor \neg P \lor R) \land(\neg S \lor \neg P \lor (S \lor \neg Q)) \land (\neg S \lor \neg P \lor P)) $$

$$ (\neg S \lor \neg P \lor R ) $$

#

$$ (\neg P \lor Q \lor ( R \land (S \lor \neg Q) \land P)) $$

$$ (\neg P \lor Q \lor R) \land (\neg P \lor Q \lor (S \lor \neg Q)) \land (\neg P \lor Q \lor P) $$

$$ (\neg P \lor Q \lor R) $$

# Konjuktive Normalform:

$$ (\neg R \lor S \lor \neg Q) \land (\neg R \lor P) \land (\neg S \lor \neg P \lor R ) \land (\neg P \lor Q \lor R) $$

# Gentzen-Formeln

$$ R \land Q \implies S $$

$$ R \implies P $$

$$ S \land P \implies R $$

$$ P \implies Q \lor R $$

#

#

$$ \neg R \land (A \lor B \lor C) \iff (\neg R \land A) \lor (\neg R \land B) \lor (\neg R \land C) $$

A ^ W = A

A v F = A

$$ (A \lor B) \lor (C \land D \land E) $$

$$ A \lor (C \land D \land E) $$

$$ (A \lor B \lor C) \land (A \lor B \lor D) \land (A \lor B \lor E) $$

## CS 16

### 4 b)

$$ S \lor \neg (P \iff (R \land \neg Q)) $$

$$ S \lor \neg ((P \rightarrow (R \land \neg Q) \land (P \leftarrow (R \land \neg Q))) $$

$$ S \lor \neg ((\neg P \lor (R \land \neg Q)) \land (P \lor \neg (R \land \neg Q))) $$

$$ S \lor \neg ((\neg P \lor (R \land \neg Q)) \land (P \lor \neg R \lor Q))) $$

$$ S \lor (P \land (\neg R \lor Q)) \lor (\neg P \land R \land \neg Q) $$

$$ ((S \lor P) \land (S \lor \neg R \lor Q)) \lor (\neg P \land R \land \neg Q) $$

$$ ((S \lor P) \lor (\neg P \land R \land \neg Q)) \land(S \lor \neg R \lor Q \lor (\neg P \land R \land \neg Q)) $$

$$ (S \lor P \lor \neg P) \land (S \lor P \lor R) \land (S \lor P \lor \neg Q) \land (S \lor \neg R \lor Q \lor (\neg P \land R \land \neg Q)) $$

$$ (S \lor P \lor R) \land (S \lor P \lor \neg Q) \land (S \lor \neg R \lor Q \lor \neg P) $$

#### Gentzen-Formeln:

$$ W \implies S \lor P \lor R $$

$$ Q \implies S \lor P $$

$$ R \land P \implies S \lor Q $$

## Allgemeiner Weg:

1. Pfeile weg!
2. Negationen reinziehen
3. Ausmultiplizieren & umformen
4. Gentzen-Formeln aufstellen

$$ (A \lor B) \land C \iff (A \land C) \lor (B \land C) $$

$$ (A \times B) / C \iff (A / C) \times (B / C) $$

$$ (A \lor B) \lor C \iff A \lor (B \lor C) \iff A \lor B \lor C $$
