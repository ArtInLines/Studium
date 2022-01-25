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
if X<Y then X := Y - X;
if X<0 then Y := X - Y
else Y := X + Y

{ Y>X; X, Y of type integer }


{ Y>X }

if X<0 ...
else ...
     (if)             (else)
{ (X<0 ^ X-Y>X) v (X>=0 ^ X+Y>X) }

if X<Y ...
{ (X<Y ^ X<0 ^ Y-X-Y > Y-X) v (X>=Y ^ X<0 ^ X-Y>X) v (X<Y ^ X>=0 ^ X+Y>X) v (X>=Y ^ X>=0 ^ X+Y>X) }

{ (X<Y ^ X<0 ^ 0>Y) v (X>=Y ^ X<0 ^ Y<0) v (X<Y ^ X>=0 ^ Y>0) v (X>=Y ^ X>=0 ^ Y>0) }

{ (X < 0  ^  Y < 0) v (X >= 0  ^  Y > 0) }
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

if X<Y ...
else Y = Y-X;
{ (X<Y ^ X<0 ^ X-(X-Y)>X) v (X<Y ^ X>=0 ^ X-Y>X) v (X>=Y ^ X-(Y-X)>X) }

{ (X<Y ^ X<0) v (X<Y ^ X>=0 ^ Y<0) v (X>=Y ^ X>Y) }
                 (Widerspruch)

{ (X<Y ^ X<0) v (X>Y) }
```
