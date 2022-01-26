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

## 5)

$$ \forall x \forall y \forall z ( \exists x1 (Q(x1, y, z) \land W(x1, y, z)) \lor \forall t(Q(t, x, z))) $$

$$ (Q(f(x, y, z), y, z) \land W(f(x, y, z), y, z)) \lor Q(t, x, z) $$

$$ f(x, y, z) => x1 $$

$$ \exists x1 (\neg Q(x1, y, z) \lor W(x1, y, z)) \lor \exists t(\neg Q(t, x, z)) $$

$$(\neg Q(f(x, y, z), y, z) \lor W(f(x, y, z), y, z)) \lor (\neg Q(g(x, y, z), x, z)) $$

$$\neg \forall Q(...) \implies \exists \neg Q(...) $$

$$\neg \exists Q(...) \implies \forall \neg Q(...) $$

$$ \exists y (P(x, y)) \lor \forall x(\neg R(x, y, x) \implies \neg \forall z Q(x, y, z)) \land \exists x \forall y (R(x, y, z)) $$

$$ \exists y1 (P(x, y1)) \lor \forall x1(\neg R(x1, y, x1) \implies \neg \forall z1 Q(x1, y, z1)) \land \exists x2 \forall y2 (R(x2, y2, z)) $$

$$ \exists y1 (P(x, y1)) \lor \forall x1(R(x1, y, x1) \lor \exists z1 \neg Q(x1, y, z1)) \land \exists x2 \forall y2 (R(x2, y2, z)) $$

$$ \forall x \forall y \forall z \exists y1 \forall x1 \exists z1 \exists x2 \forall y2 ((P(x, y1)) \lor (R(x1, y, x1) \lor \neg Q(x1, y, z1)) \land (R(x2, y2, z))) $$

$$ P(x, f(x,y,z)) \lor (R(x1, y, x1) \lor \neg Q(x1, y, g(x, y, z, x1))) \land R(h(x, y, z, x1), y2, z) $$

## 5 b)

$$\neg \exists x ( \forall y P(x, z, y) \iff \exists y Q(x, y, z)) \land \forall z R(z, y, x) $$

$$ \forall x1 \neg ( \forall y1 P(x1, z, y1) \iff \exists y2 Q(x1, y2, z)) \land \forall z1 R(z1, y, x) $$

$$ \forall x1 \neg ( (\neg \forall y1 P(x1, z, y1) \land \neg \exists y2 Q(x1,y2,z)) \lor (\forall y3 P(x1, z, y3) \land \exists y4 Q(x1,y4,z)) ) \land \forall z1 R(z1, y, x) $$

$$ \forall x1 ( ( \forall y1 P(x1, z, y1) \lor \exists y2 Q(x1,y2,z)) \land (\exists y3 \neg P(x1, z, y3) \lor \forall y4 \neg Q(x1,y4,z)) ) \land \forall z1 R(z1, y, x) $$

$$ (P(x1, z, y1) \lor Q(x1, f(x,y,z,x1,y1))) \land (\neg P(x1, z, g(x, y, z, x1, y1)) \lor \neg Q(x1, y4, z)) \land R(z1, y, x) $$

### Allgemein gilt:

$$ (\exists y1 \iff \forall y2) \implies (\neg \exists y1 \lor \forall y2) \land (\exists y3 \lor \neg \forall y4) $$

$$ \neg \exists x \forall y(...) \iff \neg \exists x (\forall y (...)) \iff \forall x (\neg \forall y (...)) \iff \forall x (\exists y \neg (...)) \iff \forall x \exists y \neg (...) $$

## 6)

```
{ X>Y ; Y>=0; X, Y of type integer }
I := 0
Z := X
while I<Y do
begin I := I + 1;
    Z := Z + 1
end
{ Z=X+Y ; X>Y ; Y>=0 ; X, Y of type integer }


Schleifen-Invariante (INV):
1. Ist in jeder Zeile wahr
2. INV ^ Schleifen-Endbedingung => Nachbeingung

{ Z = X+I ; X>Y ; Y>=0 ; X, Y integer }


1)
end
    { Z = X+I ; X>Y ; Y>=0 ; X, Y integer }

    Z := Z + 1
    { Z+1 = X+I ; X>Y ; Y>=0 ; X, Y integer }

    I := I + 1
    { Z+1 = X+I+1 ; X>Y ; Y>=0 ; X, Y integer }
    { Z = X+I ; X>Y ; Y>=0 ; X, Y integer }

while I<Y do

Z := X
{ X = X+I ; X>Y ; Y>=0 ; X, Y integer }

I := 0
{ X = X+0 ; X>Y ; Y>=0 ; X, Y integer }


2)
Nachbedingung:
{ Z=X+Y ; X>Y ; Y>=0 ; X, Y of type integer }

INV:
{ Z = X+I ; X>Y ; Y>=0 ; X, Y integer }

Schleife terminiert, wenn I=Y:

I=Y ^ INV => Nachbedingung
I=Y ^ { Z = X+I } => { Z = X+Y }


3)
Beweis, dass die Schleife terminiert:
I erhöht sich in jeder Iteration um 1 und startet als 0 und wird
dementsprechend irgendwann gleich der ganzzahligen Zahl Y sein, welche >= 0
```

### Allgemein gilt:

0. INV finden
1. Für jede Zeile (von hinten nach vorne) beweisen, dass die INV gilt
2. INV ^ Schleifen-Abbruchbedingung => Nachbedingung
3. In Worten beweisen, dass die Schleife terminiert

#### Unterschied zwischen while ... do & repeat ... until

while B do ...

repeat ... until B

1. Repeat ... until wird mindestens 1-mal augeführt
2. Schleifen-Abbruchbedingung = !B für while & = B für repeat

```
{ X > Y }
I = Y
Z = 0
repeat
    I = I + 1
    Z = Z + 1
until I = X
{ Z = X - Y }
```

1. Iteration

```
X = 2
Y = 1
I = Y+1 => 1 + 1 = 2
Z = 1 => 1
INV: Z = I - Y => 2 - 1 = 1
```

2. Iteration

```
X = 2
Y = 1
I = Y+1+1 => 3
Z = 1+1 => 2
INV: Z = I - Y => 3 - 1 = 2
```

I=X ^ INV => { Z = X - Y }
INV = In der Nachbedingung X mit I ersetzt

while (I > Y)

I = Y

INV => In der Nachbedingung Y mit I ersetzt

1.

```
until ...
    Z = Z + 1
    { Z+1 = I - Y ; ... }

    I = I + 1
    { Z+1 = I + 1 - Y ; ... }
    { Z = I - Y ; ... }
repat

Z = 0
{ 0 = I - Y ; ... }

I = Y
{ 0 = Y - Y = 0 ; ... }
```

2.  INV ^ Abbruchbedingung => Nachbedingung:

{ Z = I - Y ; ... } ^ I = X => { Z = X - Y ; ... }

3. Schleife terminiert:

-   I=Y => I<X
-   I & X sind ganze Zahlen (Integers)
-   I erhöht sich jede Iteration um 1
-   => I wird irgendwann =X sein und dann terminiert die Schleife.

1.

```
until ...
    I = I - 1
    { Z = 2 * (X - (I - 1)) = 2 * (X - I + 1) = 2 * (X - I) + 2}

    Z = Z + 2
    { Z+2 = 2X - 2I + 2 }
    { Z = 2X - 2I }
    { Z = 2 * (X - I) }
repeat

Z = 0
{ 0 = 2 * (X - I) }

I = X
{ 0 = 2 * (X - X) }
```

2. INV ^ Abbruchbedingung => Nachbedingung

{ Z = 2 _ (X - I) } ^ I=Y => { Z = 2 _ (X - Y)}

3. Schleife terminiert

-   I startet als X > Y
-   I nimmt immer um 1 ab
-   I = Y, dann endet die Schleife

# 7)

```
if ... then ...
else ...

if ... then ...
else ...

{ X > Y }

  {Geht ins if rein}
/
\
  {Geht ins else rein}


{ (Geht ins if) v (Geht ins else) }

{ (Geht in beide ifs) v (Geht ins 1. if) v (Geht ins 2. if) v (Geht in kein if) }

{ (X > Y ^ X > 0) v (X <= Y ^ X > 0) }

{ X > 0 }
```

```
if X<Y then X := Y - X
if X<0 then Y := X - Y
else Y := X + Y

{ Y>X; X, Y of type integer }


{ Y>X }

if X<0 then Y := X - Y
else Y := X + Y
     (if)             (else)
{ (X<0 ^ X-Y>X) v (X>=0 ^ X+Y>X) }

if X<Y then X := Y - X
{ (X<Y ^ Y-X<0 ^ Y-X-Y > Y-X) v (X>=Y ^ X<0 ^ X-Y>X) v (X<Y ^ Y-X>=0 ^ Y-X+Y>Y-X) v (X>=Y ^ X>=0 ^ X+Y>X) }

    (Widerspruch)
{ (X<Y ^ Y<X ^ Y<0) v (X>=Y ^ X<0 ^ Y<0) v (X<Y ^ Y>=X ^ Y>0) v (X>=Y ^ X>=0 ^ Y>0) }

                  (Die beiden lassen sich zusammen nehmen)
{ (0 > X >= Y)   v    (Y>X ^ Y>0)   v   (X >= Y > 0) }

{ (0 > X >= Y) v (Y > 0) }
```

```
if X<Y then begin if X<0 then Y := X – Y end
else Y := Y – X;
Y := X – Y;
{ Y>X; X, Y of type integer }

In C:
if (X<Y) {
    if (X<0) Y = X-Y;
}
else Y = Y-X;
Y = X-Y
{Y > X ; x, Y of type integer }

{ (in beide ifs) v (nur ins äußere if) v (nur ins else) }
```

```
{ Y>X }

Y = X-Y;
{ X-Y>X }

if X<Y then begin if X<0 then Y := X – Y end
else Y := Y – X;
{ (X<Y ^ X<0 ^ X-(X-Y)>X) v (X<Y ^ X>=0 ^ X-Y>X) v (X>=Y ^ X-(Y-X)>X) }

                 (Widerspruch)s
{ (X<Y ^ X<0) v (X<Y ^ X>=0 ^ Y<0) v (X>=Y ^ X>Y) }

{ (X<Y ^ X<0) v (X>Y) }
```
