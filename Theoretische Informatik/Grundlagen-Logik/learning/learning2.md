# CS 18

## 3)

$$X:$$
$$ {P \land S \implies Q, \neg R \iff Q, P \land \neg (S \lor \neg R)} $$

$$ \neg P \lor \neg S \lor Q, (\neg R \land Q) \lor (R \land \neg Q), P \land \neg S \land R $$

```
X:

R - P - !S - !Q
```

$$Y:$$

$$ \neg R \land S \implies \neg P, R \lor (\neg Q \lor S), R \implies \neg P \land Q $$

$$ R \lor \neg S \lor \neg P, R \lor \neg Q \lor S, \neg R \lor (\neg P \land Q) $$

```
Y:

               S
             /
  R - !P - Q
/            \
               !S

                Q
               /
        S - !P
\    /         \
    /           !Q
   /
  !R            P
     \        /
       !S - !Q
               \
                !P
```

$$Z:$$

$$ (Q \land \neg S) \lor P, (R \lor \neg S) \implies (\neg P \land R), P \lor S \implies \neg Q $$

$$ (Q \land \neg S) \lor P, (\neg R \land S) \lor (\neg P \land R), (\neg P \land \neg S) \lor \neg Q $$

```
Z:

  P - !R - S - !Q
/
\
  !P - Q - !S - R
```

X |= X

Y |= Y

Z |= Z

## 4) Beispiel

$$ S \implies ((\neg Q \lor (R \iff \neg P)) \land Q) $$

$$ \neg S \lor ((\neg Q \lor (\neg R \land P) \lor (R \land \neg P)) \land Q) $$

$$ (\neg S \lor \neg Q \lor (\neg R \land P) \lor (R \land \neg P)) \land (\neg S \lor Q) $$

$$ (\neg S \land (\neg S \lor Q)) \lor (\neg Q \land (\neg S \lor Q)) \lor (\neg R \land P \land (\neg S \lor Q)) \lor (R \land \neg P \land (\neg S \lor Q)) \ $$

$$ (\neg S \land (\neg S \lor Q)) \lor (\neg Q \land (\neg S \lor Q)) \lor (\neg R \land P \land (\neg S \lor Q)) \lor (R \land \neg P \land (\neg S \lor Q)) \ $$

$$ \neg S \lor (\neg Q \land \neg S) \lor (\neg R \land P \land \neg S) \lor (\neg R \land P \land Q) \lor (R \land \neg P \land \neg S) \lor (R \land \neg P \land Q) $$

$$ \neg S \lor (\neg R \land P \land \neg S) \lor (\neg R \land P \land Q) \lor (R \land \neg P \land \neg S) \lor (R \land \neg P \land Q) $$

$$ ... $$

### alternativ fangen wir mit "& Q" an:

$$ \neg S \lor ((\neg Q \lor (\neg R \land P) \lor (R \land \neg P)) \land Q) $$

$$ \neg S \lor (\neg R \land P \land Q) \lor (R \land \neg P \land Q) $$

$$ (\neg S \lor \neg R \lor R) \land (\neg S \lor \neg R \lor \neg P) \land (\neg S \lor \neg R \lor Q) \land (\neg S \lor \neg P \lor R) \land (\neg S \lor \neg P \lor \neg P) \land (\neg S \lor \neg P \lor Q) \land (\neg S \lor \neg Q \lor R) \land (\neg S \lor \neg Q \lor \neg P) \land (\neg S \lor \neg Q \lor Q) $$

$$ (\neg S \lor \neg P) \land (\neg S \lor \neg R \lor Q) \land (\neg S \lor \neg Q \lor R) $$

$$ Gentzen-Formeln: $$

$$ S \land P \implies Falsch, $$
$$ S \land R \implies Q, $$
$$ S \land Q \implies R $$

# Allgemein gilt:

$$ A \lor Falsch \iff A $$

$$ A \land Wahr \iff A $$

Äußerer Operator hat sich geändert:

$$ A \lor (B \land C) \iff (A \lor B) \land (A \lor C) $$

$$ (A \land B) \lor (C \land D) \iff (A \lor C) \land (A \lor D) \land (B \lor C) \land (B \lor D) $$
