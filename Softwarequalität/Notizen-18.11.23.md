## Klausur:
- 2 doppel-seitig beschriebene DIN A4 Seiten dürfen mitgenommen werden (dürfen auch bedruckt sein)

## Kapitel 5: Qualitätssicherung
- 3 Arten:
  - Software-Test
  - Statische Analyse
    - Softwaremetriken         (siehe z.B. Komplexitätsmetriken von Kapitel 4)
    - Konformitätsmetriken     (Einschränkung der Sprache und Check dass diese Einschränkung eingehalten wird; z.B. Misra C)
    - Manuelle Softwareprüfung (z.B. Code-Review)
  - Software-Verifikation      (hier grßtenteils ignoriert)
- Arten an Tests:
  - Unit-Test         (Test auf Ebene von Funktionen, Klassen, Modulen)
  - Integrations-Test (Testet Komposition unterschiedlicher Komponenten)
  - System-Test       (System wird als Ganzes bezogen auf (Pflichtenheft-)Anforderungen getestet)
  - Abnahme-Test      (Systemtest, aber getestet vom Kunden. Oft juristisch wichtig für Projekt-Abschluss)
- Weitere Arten an Tests:
  - Funktional
    - Funktionstest       (wird die erwünschte Funktionalität erfüllt)
    - Trivialtest         (funktioniert es mit trivialen Werten (z.B. geteilt duch 0))
    - Crashtest           (können wir die Software crashen mit z.B. zu hohen Input-Werten)
    - Kompatibilitätstest (ist die Software mit anderer Software kompatibel)
    - Zufallstest         (Crasht die App bei zufällig generierten Inputs)
  - Operational
    - Installationstest (Testet die Installation der Software)
    - Ergonomietest     (UX, Accessibility)
    - Sicherheitstest   (ist die Software sicher)
  - Temporal
    - Komplexitätstest
    - Laufzeittest
    - Lasttest   (Test mit erwarteter Maximallast)
    - Stresstest (überschreitet die Software die Anforderungen (z.B. höhere Last als erwartet; weniger RAM als erwartet; etc.))
- Äquivalenzklassen
  - Man kann i.d.R. nicht alle möglichen Eingaben testen
  - deswegen teilen wir die Eingabemenge in unterschiedliche Teile (Äquivalenzklassen)
  - wir nehmen an, dass wenn die Funktion für einen Repräsentanten einer Äquivalenzklasse erfolgreich funktioniert, es für alle Elemente der Äquivalenzklasse gilt
  - Für Funktion "abs" (absolute Wert) würden z.B. die Äquivalenzklassen "negative Zahlen", "positive Zahlen", "0" gebildet
  - Mehrdimensionale Äquivalenzklassen (siehe S. 280)
  - Partielle Partitionierung (nur valide Eingabewerte werden getestet)
  - Vollständige Partitionierung (auch invalide Eingabewerte werden getestet)
    - bei invaliden Eingaben wird jeder Ausgabewert akzeptiert, solange die Software nicht crasht
  - Grenzwertbetrachtung testet die Werte an den Enden jeder Äquivalenzklasse sowie die Werte daneben, die außerhalb der Äquivalenzklasse liegen
- Zustandbasierte Tests
  - Oft beruhen Funktionen auf Zuständen, die geändert werden (siehe Ringbuffer Bsp auf S. 286)
  - Für Test sollte Zustandsdiagramm erstellt werden
  - Jeder möglicher Zustand muss dann getestet werden
- White-Box-Tests:
  - Ziel: Alle nötigen Fälle mit Tests abdecken
  - Zuerst wird Kontrollflussgraph (wie bei zyklomatischer Komplexität) erstellt
  - Dann gibt es unterschiedliche Levels der Test-Abdeckung (Auf Folien stehen viele Abdeckungsarten, aber nur die folgenden sind wirklich relevant)
    1. Anweisungsüberdeckung (C0)   -> alle Knoten des Graphen werden abgedeckt
    2. Zweicküberdeckung (C1)       -> alle Zweige (Edges) werden abgedeckt
    3. McCabe-/Pfadüberdeckung (C2) -> alle Pfade des Graphen werden abgedeckt
  - Pfadüberdeckung kann bei bestimmten Algorithmen sehr aufwendig und komplex werden
  - Überdeckungsmetrik = Anzahl der überdeckten Knoten o. Kanten / Anzahl an Knoten o. Kanten
- Datenflussanalyse
  - Um Datenfluss zu analysieren, müssen Variablenzugriffe analysiert werden. Es gibt die folgenden Arten an Variablenzugriff
    - def-use: Überschreibt den Wert der Variable
    - c-use:   Nutzt Variable für eine Berechnung
    - p-use:   Nutzt Variable für eine Entscheidung
  - Datenfluss kann mit Kontrollfluss kombiniert werden (siehe S. 306)
  - Man kann auch Testabdeckung basierend auf Datenflusskriterien machen (wird in Praxis fast nie verwendet)
- Statische Analyse
  - Analyisiert den Code vor der Ausführung
  - interne Analyse vom Compiler selbst gibt es bei allen modernen Compilern
  - externe Analyse mit gesonderten Tools gibt es auch
- Manuelle Analyse
  - Walkthrough (Informelles Durchgehen den Codes von min. 2 Entwickler:innen)
  - Review      (formalisiertes Walkthrough, z.B. mithilfe von Checklisten)
  - Inspektion  (stark formalisiert mit verschiedenen Rollen)
- Software-Verifikation
  - Mathematische Formalisierung der Implementierung und der Spezifikation, um die Implementierung mathematisch vollständig verifizieren zu können
  - verifiziert die Software, validiert sie aber nicht (sprich, wenn ein Fehler in der Spezifikation ist, dann kann die Sotware trotzdem als verifiziert gelten)

## Übungen

### 1)

```c

/* mathetricks: Einige Tricks mit Mathe */
/* Parameter: a: Multiplikator */
/* b: Divisor (darf nicht 0 sein) */
/* Rückgabe: Die Rechnung, ist nie negativ! */
int mathe_tricks(int a, int b)
{
	assert(b != 0);
	int c;
	c = a/b;
	c *= a;
	c *= b;
	assert(c >= 0);
	return c;
}
```

### 2)

Äquivalenzklassen:

- $x \le 3$
- $3 \lt x \le 5$
- $5 \lt x \le 8$
- $8 \lt x$

### 3)

$s = \{c | c \in [0, 255]\}$
- $len(s) \lt 4$ (Ergebnis False)
- $len(s) \gt 4$ (Ergebnis False)
- $len(s) = 4 \land \exists c \in s (c \lt '0' \lor c \gt '9')$ (Ergebnis False)
- $len(s) = 4 \land \forall c \in s (c \ge '0' \land c \le '9') \land \lnot valid\_pin(s)$ (Ergebnis False)
- $len(s) = 4 \land \forall c \in s (c \ge '0' \land c \le '9') \land valid\_pin(s)$ (Ergebnis True)

### 4), 5)

siehe Blatt
