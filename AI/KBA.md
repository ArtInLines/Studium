# Knuth-Bendix Algorithmus

```
1 * x = x;
i(x) * x = 1;
(x * y) * z = x * (y * z);
```

```
s = 1 * (x * i(y))

   * []
  /    \
 1 [1]  * [2]
       / \
[2, 1]x   i[2, 2]
          |
	      y[2, 2, 1]


s[[2, 1] |-> y*z] = 1 * ((y*z) * i(y))



o = [x |-> y*z, 1 |-> i(z), i(x) |-> z]
so = i(z) * ((y*z) * i(y))

o = [a -> b, b -> c]
s = a * b * c
so = b * c * c
```

```
Bsp. für 2. Regel

E = {
	a = b * a
}
o = {}

- 2. Regel
- Hat keine Löung


Bsp. für 5. Regel

E = {
	a * (b * c) = x * y,
	i(a) = 1,
	i(b * c) = a
}
o = {}

- 5. Regel
E = {
	a = x,
	(b*c) = y,
	i(a) = 1,
	i(b * c) = a
}
o = {}



Bsp. für 6. Regel

E = { a * b = x * y * z}
- 6. Regel
- Hat keine Lösung

```


```
Bsp. Aufgabe

Geg.: <{p(x1, f(x4)) = p(x2, x3)}, []>

-> <{x1 = x2, f(x4) = x3}, []> (Regel. 5)

-> <{X1 = x2, x3 = f(x4)}, []> (Regel. 3)

-> <{x3 = f(x4)}, [x1 |-> x2]> (Regel. 1)

-> <{}, [x1 |-> x2, x3 |-> f(x4)]> (Regel. 1)
```

Knuth-Bendix Algorithmus

- weight(term) Fkt.
	- weight(var) = 1
	- $weight(f(t_1, ..., t_n)) = weight(f) + \sum_{i=1}^n{weight(t_i)}$
	- weight(*) = 1
	- weight(i) = 0
- count(term, var) Fkt.
  - Wie oft kommt `var` im Term `term` vor
  - $count(x, x) = 1$
  - $y\ne x \rightarrow count(y, x) = 0$
  - $count(f(t_1, ..., t_n), x) = \sum{count(t_i, x)}$


1. Definiere weight für Funktions-Symbole
	- Bei allen Gleichungen $l \approx r$ muss $weight(l) \ne weight(r)$ gelten
2. Gleichungen als Termersetzungs-Regeln schreiben
   - also statt $l \approx r$ dann $l \rightarrow r$ schreiben
3. Finde alle kritischen Paare

Def. Kritisches Paar:
1. $l_1 = r_1$
2. $l_2 = r_2$

erstellt ein kritisches Paar g.d.w. $l_1$ einen Teilterm $t$ an Position $u$ hat (der keine Variable ist) und $t$ mit $l2$ unifizierbar ist.

Die Substitution $o$ die wir in der Unifikation erhalten haben, gibt uns das kritische Paar:

- $l_1o \rightarrow r_1o$
- $l_1o \rightarrow l_1o[u \mapsto r_2o]$

Kritische Paar: <$r_1o, r_2o$>




## Bsp.:

Geg.:
1. $(x * y) * z \rightarrow x * (y * z)$
2. $i(a) * a \rightarrow 1$

Wir versuchen $<\{x * y = i(a) * a\}, []>$ zu unifizieren.

-> <{$x = i(a), y = a$}, []>

-> <$\{y = a\}, [x \mapsto i(a)]$>

-> <$\{\}, [y \mapsto a, x \mapsto i(a)]$>

Also das kritische Paar ist jetzt:

- $((x * y) * z)o \rightarrow (x * (y * z))o$
- $(i(a) * a) * z \rightarrow i(a) * (a * z)$

Für die 2. dann
- $((x * y) * z)o \rightarrow l_1o[u \mapsto r_2o]$
- $(i(a) * a) * z \rightarrow ((i(a) * a) * z)[[1] \mapsto (1)o]$
- $(i(a) * a) * z \rightarrow ((i(a) * a) * z)[[1] \mapsto 1]$
- $(i(a) * a) * z \rightarrow 1 * z$

Kritische Paar:

<$i(a)*(a*z), 1*z$>

Regel: $i(a) * (a*z) \rightarrow z$


### 2. Beispiel

1. $i(a) * (a * z) \rightarrow z$
2. $i(x) * x \rightarrow 1$

Position $u = [2]$. Wir unifizieren:

- <{$(a * z) = i(x) * x$}, []>
- <{$a = i(x), z = x$}, []>
- <{}, [$a \mapsto i(x), z \mapsto x$]>

Nächster Schritt:

$l_1o \rightarrow r_1o$
- $(i(a) * (a * z))o \rightarrow zo$
- $i(i(x)) * (i(x) * x) \rightarrow x$

$l_1o \rightarrow l_1o[u \mapsto r_2o]$
- $(i(a) * (a * z))o \rightarrow (i(a) * (a * z))o[u \mapsto r_2o]$
- $i(i(x)) * (i(x) * x) \rightarrow i(i(x)) * (i(x) * x)[[2] \mapsto 1o]$
- $i(i(x)) * (i(x) * x) \rightarrow i(i(x)) * (i(x) * x)[[2] \mapsto 1]$
- $i(i(x)) * (i(x) * x) \rightarrow i(i(x)) * 1$

Kritische Paar: <$x, i(i(x))*1$>

Neue Regel: $i(i(x))*1 \rightarrow x$


