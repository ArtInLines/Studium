## Def. Gruppe (aus der Gruppentheorie)

Eine Gruppe ist ein 4-Tupel der Form <$G, e, *, i$>
wobei gilt:
- $e \in G$ (das neutrale Element)
- $*: G x G \rightarrow G$
- $i: G \rightarrow G$ (das Inverse)
- Es gelten die folgenden Axiome:
  - $\forall x \in G: e*x = x$
  - $\forall x\in G: i(x)*x= e$
  - $\forall x,y,z \in G: (x * y)*z = x*(y*z)$

## Def. Signatur

$\Sigma = <V,F, arity>$ wobei gilt:
- $V$ ist Menge der Variablen
- $F$ ist Menge der Funktionszeichen
- $arity: F \rightarrow \N$, gibt pro Funktion an, wie viele Argumente diese Funktion als Input bekommt
- $V \cap F = \emptyset$ (Variablen müssen ungleich Funktionszeichen sein)

## Def. Sigma-Terme

$\mathcal{T}_\Sigma$ ist die Menge von $\Sigma$-Termen ist induktiv definiert:
1. $x \in \mathcal{T}_\Sigma$ für alle Variablen $x$
2. $c \in \mathcal{T}_\Sigma$ für alle Funktionszeichen $c$, bei denen gilt: $arity(c) = 0$
3. Falls $f$ ein Funktionszeichen ist und $n = arity(f)$ und $n > 0$ und $t_1, ..., t_n \in \mathcal{T}_\Sigma$, dann gilt: $f(t_1, ..., t_n) \in \mathcal{T}_\Sigma$

## Def. Sigma-Gleichung

Damit sagen wir, dass zwei Terme logisch gleich sind (z.B. 1*x = x ist logisch, aber nicht syntaktisch gleich)

Wir schreiben $<s, t>$ oder auch $s \approx t$, g.d.w. s logisch gleich t ist.

## Def. Sigma-Algebra

Sei $\Sigma$ eine Signatur, dann ist $\mathcal{A} = <A, \mathcal{I}>$ eine Algebra, g.d.w.:
1. $A$ ist ein nicht-leeres Universum. (Das Universum enthält alle Symbole, die wir haben können)
2. $\mathcal{I}$ ist die Interpretation der Funktions-Symbole. Für alle $f \in F$ gilt: $\mathcal{I}(f): A^{arity(f)} -> A$. Wir schreiben auch $f^{\mathcal{A}}$ für die Interpretation

Die Menge aller $\Sigma$-Algebras schreiben wir als $Alg(\Sigma)$

## Def. Variablen-Belegung

Sei $\Sigma$ eine Signatur und $\mathcal{A}$ eine Algebra, dann definieren wir $I$ als Variablen-Belegung wie folgt:

$I: V \rightarrow A$

Jede Variable wird einem Element aus dem Universum $A$ zugeordnet

## Def. Anwendung

Die Anwendung $eval$ ist wie folgt definiert:

1. $eval(x, I) := I(x)$ für alle $x \in V$
2. $eval(c, I) := c^{\mathcal{A}}$ für alle Konstanten $c \in F$ (also es gilt $arity(c) = 0$)
3. $eval(f(t_1, ..., t_n), I) := f^{\mathcal{A}}(eval(t_1, I), ..., eval(t_n, I))$

## Def. Gültige Gleichung

Eine Gleichung $s \approx t$ ist gültig g.d.w. $eval(s, I) = eval(t, I)$ für alle Variablen-Belegungen $I: V -> A$ gilt.

Wir schreiben das auch als $\mathcal{A} \models s \approx t$

## Def. $E$-Varietät

Sei $E$ eine Menge von $\Sigma$-Gleichungen, dann ist die $E$-Varietät die Menge aller $\Sigma$-Algebras, die die Gleichungen in $E$ erfüllen.

Variety(E) := $\{\mathcal{A} \in Alg(\Sigma) | \forall(s \approx t) \in E: \mathcal{A} \models s \approx t\}$

## Def. logische Konsequenz

Die Gleichung $s \approx t$ ist eine logische Konsequenz g.d.w.

Für alle $\mathcal{A} \in Variety(E)$ muss $\mathcal{A} \models s \approx t$

Wir schreiben dann auch $E \models s \approx t$

Falls $E \models s \approx t$ gilt, dann gilt auch $E \models t \approx s$

## Def. Sigma-Substitution

Die Substitution $\sigma: V \rightarrow \mathcal{T}_\Sigma$

Wir schreiben auch $\sigma = \{ x_1 \rightarrow t_1, ..., x_n \rightarrow t_n \}$

Die Anwendung einer Substition (wir schreiben $x\sigma$) ist wie folgt definiert:

1. Für alle Variablen $x$, gilt: $x\sigma =\sigma(x)$
2. Für alle Konstanten $c$ gilt: $c\sigma = c$
3. Für alle Funktionen $f$ gilt: $f(t_1, ..., t_n)\sigma=f(t_1\sigma, ..., t_n\sigma)$

## Induktive Def. der Relation $\vdash$ ("Beweis"-Relation)

1. $E \vdash s \approx t$ für alle Gleichungen $(s \approx t) \in E$
2. $E \vdash s \approx s$ für alle Terme $s$
3. Falls $E \vdash s \approx t$ dann gilt auch $E \vdash t \approx s$
4. Falls $E \vdash r \approx s$ und $E \vdash s \approx t$ dann gilt auch: $E \vdash r \approx t$
5. Falls $n = arity(f)$ und für alle $i = 1,...,n$ $E \vdash s_i \approx t_i$ gilt, dann gilt auch: $E \vdash f(s_1, ..., s_n) \approx f(t_1, ..., t_n)$
6. Falls $E \vdash s \approx t$und $\sigma$ eine Substitution ist, dann gilt auch $E \vdash s\sigma \approx t\sigma$

## Induktive Def. der Menge Pos(t)

```
Bsp.:
1 * (x + y)
Das können wir uns wie folgt vorstellen:

   *
  / \
 1   +
    / \
   x   y

Wir wollen die einzelnen Terme individuell ansprechen können und müssen deswegen deren Position definieren.
In diesem Beispiel:
- 1*(x + y) ist an Postion []
- 1 ist an Position [1]
- x + y ist an Position [2]
- x ist an Position [2, 1]
- y ist an Positon [2, 2]
```

$Pos(t)$ ist die Menge aller Positionen in einem Term $t$ und ist wie folgt definiert:

1. Für jede Variable $x$ gilt: $Pos(x) := \{[]\}$
2. Für jede Konstante $c$ gilt: $Pos(c) := \{[]\}$
3. Für jede Funktion $f$ gilt: $Pos(f(t_1, ..., t_n)) := \bigl\{ [\;] \bigr\} \cup \bigcup\limits_{i=1}^n \bigl\{ [i] + u \mid u \in Pos(t_i) \bigr\}$

## Def. Teilterm

Wenn $t$ ein Teilterm von $s$ ist und an der Position $u$ in $s$ ist, dann schreiben wir $s/u = t$. Wir definieren $s/u$ induktiv wie folgt:

1. $s/[] := s$
2. $f(s_1, ..., s_n)/([i] + u) := s_i/u$

## Def. Termersetzung

Wir können den Teilterm an der Position $u$ in $s$ mit einem Term $t$ ersetzen und schreiben dann $s[u \rightarrow t]$. Wir definieren das induktiv:

1. $s[[] \rightarrow t] := t$
2. $f(s_1, ..., s_n)[[i] + u \rightarrow t] := f(s_1, ..., s_i[u \rightarrow t], ..., s_n)$


## Def. Termersetzungs-Ordnung

Die Relation $\prec$ ordnet $\Sigma$-Terme. Wir definieren diese Ordnung wie folgt:

1. Für alle $s \in \mathcal{T}_\Sigma$ gilt: $\lnot(s \prec s)$
2. Für alle $r,s,t \in \mathcal{T}_\Sigma$ gilt: Falls $r \prec s$ und $s \prec t$ dann gilt auch $r \prec t$
3. Für alle $r,s \in \mathcal{T}_\Sigma$ und Substitionen $\sigma$ gilt: Falls $r \prec s$ dann gilt auch $r\sigma \prec s\sigma$
4. Für alle $s,l,r \in \mathcal{T}_\Sigma$ und Positionen $u \in Pos(s)$ gilt: Falls $r \prec l$ dann gilt auch $s[u \rightarrow r] \prec s[u \rightarrow l]$
5. Es gibt eine Folge $(s_n)_{n \in \N}$ mit $s_{n+1} \prec s_n$ (in anderen Worten, es gibt eine Folge, die immer kleinere Terme liefert)
6. Für alle $(l \approx r) \in E$ gilt $l \prec r$

## Regeln von Martelli & Montanari zur Lsg. von syntaktischen Gleichungssystemen

Syntaktische Gleichung schreibt sich als $s \doteq t$. Ein syntaktisches Gleichungssystem ist eine Menge solcher Gleichungen.

1. Falls $y \in V \land y \notin Vars(t)$, dann können wir $<E \cup \{y \doteq t\}, \sigma>$ zum folgendem umformen: $<E\{y \rightarrow t\}, \sigma\{y \rightarrow t\}>$
2. Falls $y \in V \land y \in Vars(t) \land y \neq t$, dann können wir $<E \cup {t \doteq y}, \sigma>$ zum folgendem umformen: $\Omega$ (kein mögliches Ergebnis)
3. Falls $y \in V \land t \notin V$, dann können wir $<E \cup \{t \doteq y\}, \sigma>$ zum folgendem umformen: $<E \cup \{y \doteq t\}, \sigma>$
4. Falls $x \in V$, dann können wir $<E \cup \{x \doteq x\}, \sigma>$ zum folgendem umformen: $<E, \sigma>$
5. $<E \cup \{f(s_1, ..., s_n) \doteq f(t_1, ..., t_n)\}, \sigma>$ zum folgendem umformen: $<E \cup \{s_1 \doteq t_1, ..., s_n \doteq t_n\}, \sigma>$
6. $f \neq g$ dann gibt es keine Lösung für $<E \cup \{f(...) \doteq g(...)\}, \sigma>$ (also wird zu $\Omega$)

## Def. Most General Unifier

Falls $<E, \{\}>$ zu $<\{\}, \mu>$ mit diesen Regeln umgeformt werden kann, dann ist $mu$ der Most-general-unifier, auch $mgu(E)$ genannt