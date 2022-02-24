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


$$
\exists x1 (P(x1, y, z) \land \forall y1 (Q(x1, y1, z)))
$$

$$
\forall y \forall z \exists x1 \forall y1 \exists x2(P(x1, y, z) \land Q(x1, y1, z))
$$

$$
(P(f(y, z), y, z) \land Q(f(y, z), y1,g(y, z, y1)))
$$


```
{ X>Y ; Y>=0; X, Y of type integer }
I := X;
Z:=0;
while I > Y:
    Z := Z + 2;
    I := I - 1
{ Z=2*(X-Y) ; X>Y ; Y>=0 ; X, Y of type integer }

INV = { Z = 2*(...-...) }

2.)
INV ^ Abbruchbedingung => Nachbedingung

{ Z = 2*(X-I); X>Y; ...} ^ !(I > Y) => {Z=2*(X-Y)}

3.)
Ist keine Endlosschleife, weil die Abbruchbedingung in endlicher Zeit eintrifft.

```


```
Y := Y - X;
if X<0 then
    if Y<0 then Y := X * Y
        else Y := Y - X
{ Y>0; X, Y of type integer }

{Y>0}

if X<0 then
    if Y<0 then Y := X * Y
        else Y := Y - X
{ (Y>0 ^ X>=0) v (X*Y>0 ^ X<0 ^ Y<0) v (X<0 ^ Y>=0 ^ Y-X>0) }

Y := Y - X;
{ (Y-X>0 ^ X>=0) v (X*(Y-X)>0 ^ X<0 ^ Y<0) v (X<0 ^ Y-X>=0 ^ Y-X-X>0) }

{ (Y>X ^ X>=0) v (0>Y>X) v (X<0 ^ Y>2X) }
```

---

$$
21^{35} mod (43)
$$

$$ 21^{32} * 21^{3} mod(43)$$

$$ 21^{2^{2^{2^{2^2}}}} * 21^{3} mod(43) $$

$$ 21^2 = 441 \equiv 11 $$

$$ 11^{2} = 121 \equiv 35 $$

$$ 35^{2} = 1225 \equiv 21 = 21^8 $$

$$ 21^8 * 21^4 \equiv 21 * 35 $$
