## Automatisches Differenzieren

Berechnungsgraph ist eine Liste von Berechnungsknoten.

1. Variablen-Knoten $(x,)$ wobei $x \in \{x_1, ..., x_n\}$
2. Konstanten-Knoten $(n,r)$ interpretiert als $n := r$ wobei $n$ der Name und $r$ der reele wert ist
3. unärer Knoten $(n, f, a)$ interpretiert als $n := f(a)$ wobei $n$ ein Name ist, $f$ eine Fkt. ist und $a$ ein weiterer Berechnungsknoten ist.
4. binärer Knoten $(n, f, a, b)$ interpretiert als $n := f(a, b)$ wobei " und $a, b$ Berechnungsknoten sind.

Beispiel: $3.14 \cdot sin(x)$

Der Berechnungsgraph (BG) sieht dabei wie folgt aus:

$[(x,), (v_1, 3.14), (v_2, sin, x), (y, \cdot, v_1, v_2)]$

BG ist zulässig g.d.w. für jeden binären Knoten  $(n, f, a, b)$ und für jeden unären Knoten $(n, f, c)$ der im BG vorkommt, kommen $a, b, c$ vorher im BG vor.

Elternknoten: Falls ein BG zulässig ist, dann gilt für die Knoten $a, b$, dass der Knoten $(n, f, a, b)$ dessen Elternknoten ist und dass für den Knoten $c$ der Knoten $(n, f, c)$ dessen Elternknoten ist.

Bemerkung: $y$ ist bei uns immer der letzte Knoten eines BGs und damit der Ausgabeknoten.

Das Adjungierte von einem Knoten $v$ ist $\bar v = \frac{\partial y}{\partial v}$

Angenommen $p_1, ..., p_k$ sind die Elternknoten von $v$, dann gilt:

$$\bar v = \sum_{i=1}^{k}\frac{\partial y}{\partial p_i} \cdot \frac{\partial p_i}{\partial v} = \sum_{i=1}^{k} \bar p_i \cdot \frac{\partial p_i}{\partial v}$$

Beispiel: $y = sin(x_1 + x_2) + cos(x_1 - x_2) \cdot (x_1 + x_2)$

BG = $[(x_1,), (x_2,), (v_1, +, x_1, x_2), (v_2, -, x_1, x_2), (v_3, sin, v_1), (v_4, cos, v_2), (v_5, \cdot, v_4, v_1), (y, +, v_3, v_5)]$

Gegeben $x_1 = \frac{\pi}2, x_2 = \frac{\pi}4$ dann gilt:
- $v_1 = \frac{3\pi}{4}$
- $v_2 = \frac{\pi}{4}$
- $v_3 = \frac{\sqrt{2}}2$
- $v_4 = \frac{\sqrt{2}}2$
- $v_5 = \frac{3\pi\sqrt{2}}{8}$
- $y = \frac{(4 + 3\pi)\sqrt{2}}{8}$

Damit können wir jetzt alle Adjungierten berechnen:

- $\bar y = \frac{\partial y}{\partial y} = 1$
- $\bar v_5 = \bar y \cdot \frac{\partial y}{v_5} = \bar y \cdot (\frac{\partial v_3}{\partial v_5} + \frac{\partial v_5}{\partial v_5}) = 1 \cdot (0 + 1) = 1$
- $\bar v_4 = \bar v_5 \cdot \frac{\partial v_5}{\partial v_4} = v_1 = \frac{3\pi}4$
- $\bar v_3 = \bar y \cdot \frac{\partial y}{\partial v_3} = 1 \cdot (1 + 0) = 1$
- $\bar v_2 = \bar v_4 \cdot \frac{\partial v_4}{\partial v_2} = \bar v_4 \cdot (-sin(v_2)) = \frac{3\pi}4 \cdot (-sin(\frac{\pi}4)) = \frac{3\pi - 2\sqrt2}{4}$
- $\bar v_1 = \bar v_3 \cdot \frac{\partial v_3}{\partial v_1} + \bar v_5 \cdot \frac{\partial v_5}{\partial v_1} = cos(v_1) + v_4 = \frac{\sqrt2}2 + \frac{\sqrt2}2 = \sqrt2$
- $\bar x_2 = \bar v_1 \cdot \frac{\partial v_1}{\partial x_2} + \bar v_2 \cdot \frac{\partial v_2}{\partial x_2} = \bar v_1 - \bar v_2 = \sqrt{2} - \frac{3\pi - 2\sqrt2}{4}$
- $\bar x_1 = \bar v_1 \cdot \frac{\partial v_1}{\partial x_1} + \bar v_2 \cdot \frac{\partial v_2}{\partial x_1} = \bar v_1 + \bar v_2 = \sqrt{2} + \frac{3\pi - 2\sqrt2}{4}$
