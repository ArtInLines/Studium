## Def. CSP

```
P = <Vars, Values, Constraints>
```
wobei gilt:
- Vars ist eine Menge möglicher Variablen (Strings)
- Values ist eine Menge möglicher Werte, die Variablen zugeordnet werden können (Strings)
- Constraints ist eine Menge von Funktionen der Prädikatenlogik (also boolsche Funktionen)

Variablenbelegung $A$ ist eine Funktion $A: Vars -> Values$

Ein Variablenbelegung $A$ ist eine Lösung des CSPs g.d.w. gilt:
$eval(f, A) = true$ für alle $f \in Constraints$

Ein partielle Variablenbelegung $B$ ist eine Funktion $B: Vars -> Values \cup \{\Omega\}$

## Bsp. Map Colouring

siehe Skript

## Bsp. 8-Damen-Problem

Schachbrett ist 8x8 und wir haben 8 Damen.
Pro Zeile, Spalte & Diagonale darf jeweils nur eine Dame gesetzt werden.

Ansatz: Jede Variable ist eine Zeile und der Wert ist jeweils die Spalte der Dame

```
Vars := {V1, V2, V3, V4, V5, V6, V7, V8}
Values := {1, 2, 3, 4, 5, 6, 7, 8}
```

DifferentColumns := $\{ Vi \ne Vj | i, j \in \{1, ..., 8\} \land i \ne j \}$

DifferentDiagonals := $\{ |i - j| \ne |Vi - Vj| | i, j \in \{1, ..., 8\} \land i \ne j \}$

Constraints := DifferentColumns $\cup$ DifferentDiagonals

## Def. Augmentiertes CSP

```
P = <Vars, Values, {<f, Variables(f)> | f in Constraints}>
```

## Def. Konsistenz

EIn Wert $v$ ist konsistent für die Variable $x$ bzgl. des Constraints $f$ g.d.w. die partielle Variablenbelegung {$x \rightarrow v$} erweitert werden kann zu einer Variablenbelegung $A$ sodass eval(f, A) = true

## Z3

```py
import z3

boys  = z3.Int('boys')
girls = z3.Int('girls')

S = z3.Solver()

S.add(boys - 1 == girls)
S.add(2 * (girls - 1) = boys)
S.check()
solution = S.model()

b = solution[boys].as_long()
g = solution[girls].as_long()

print(f"There are {b} sons & {g} daughters")
```

666€ für Pinguin + Papagei

600€ mehr für Pinguin als für Papagei

```py
import z3

parrot  = z3.Real("parrot")
penguin = z3.Real("penguin")

S = z3.Solver()

S.add(parrot + penguin == 666)
S.add(parrot + 600 == penguin)
S.check()
solution = S.model()

p = solution[parrot].as_decimal()

print(f"The parrot costs {p}€")
```