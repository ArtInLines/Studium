# 1)

Ein umfangreiches Softwareprojekt wurde in der Programmiersprache Pascal geschrieben und umfasst 50.000 Zeilen Code.
Das Projekt soll in der Programmiersprache C neu geschrieben werden. Wieviele Codezeilen wird die Neuimplementierung vorraussichtlich umfassen?

---

Es wird vermutlich 7/5 (bzw. 1.4) mal so viele Lines of Code werden.

# 2)

Bestimmen Sie den Aufwand (Effort) nach Halstaed, um das unten abgedruckte Programm zu verstehen.
Es wurde festgelegt, dass folgende Programmelemente als Operatoren gelten:
alle C-Schlüsselwörter, Funktionen, Semikolon, Klammern(eckig, rund, geschweift) werden gruppiert

```c
void sort(int *a, int n)
{
	int i, j, t;
	if (n < 2)
		return;
	for (i = 0; i < n -1; i++)
	{
		for (j = i+1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
}
```

---

- void sort int * () {} [] ; , if < return for = - ++ + >
- a, n, i, j, t 2 1 0
- n1 = 16
- n2 = 8
- n  = 26
- N1 = 51
- N2 = 33
- N  = 84
- D  = 8 * 33/8 = 33
- V  = 84 * log2(26) = 385.14
- E  = 33 * 385.14 = 12709.5

# 3)

Beschreiben Sie den Unterschied zwischen Komponenten- und Strukturmetriken für objektorientierte Softwaremetriken

---

Komponentenmetriken berechnen jeweils nur Metriken für die interne Komplexität der Klassen.
Strukturmetriken dagegen berechnen die Komplexität, die durch die Verbindungen zwischen den Klassen entstehen.

# 4)

Der neue Mainframe der SilvermanSocks Bank soll eine Verfügbarkeit von 99,95% bieten. Der Neustart nach einem Fehler dauert 8min.
Welche mittlere Zeit zwischen zwei Fehlern muss das System lauffähig sein, um die geforderte Verfügbarkeit einzuhalten?

---

```
MTTR = 8min
A    = 99.5%

A = MTBF / (MTBF + MTTR)
A*MTBF + A*MTTR = MTBF
A*MTTR = (1 - A)*MTBF
0.9995*8min = (1 - 0.9995)*MTBF
7.996min = 0.0005*MTBF
7.996min/0.0005 = MTBF
15992min = MTBF
1332.666h = MTBF
```

# 5)

Der Webvideodienst netflux betreibt seine Server mit einer MTBF von 96h. Nach einem Fehler dauert der Neustart 14min.
Welche Verfügbarkeit kann der Dienst anbieten?

---

```
MTBF = 96h = 5760min
MTTR = 14min
A = MTBF / (MTBF + MTTR)
A = 5760 / (5760 + 14)
A = 5760 / 5774
A = 0.9976
A = 99.76%
```

# 6)

Berechnen Sie die zyklomatische Komplexität für nachfolgende C-Funktion und bewerten Sie das Risiko:
```c
void zaehlezeichen( int* vokalanzahl, int* gesamtzahl )
{
	char zeichen;
	cin >> zeichen;
	while( (zeichen >= 'A') && (zeichen <= 'Z') && (*gesamtzahl < INT_MAX) )
	{
		*gesamtzahl++;
		if( (zeichen=='A') || (zeichen=='E') || (zeichen=='I') || (zeichen=='O') ||(zeichen=='U') )
		{
			*vokalanzahl++;
		}
		cin >> zeichen;
	}
}
```

---

```
        zaehlezeichen
			|
			v
		cin>>zeichen
		    |
			v
		while(...) <-------------
	  /		|                     \
	 /		v                      |
	|	*gesamtzahl++              |
	|	    |                      |
	|		v                      |
	|	if(...) -> *vokalanzahl++ /
	|		  \		|           /
	|		   |    |         /
	|		   v	v       /
	|		 cin>>zeichen -
	v
	}
```

Kanten: 9
Knoten: 8
Komponenten: 1
V(G) = 3
Niedrige Komplexität