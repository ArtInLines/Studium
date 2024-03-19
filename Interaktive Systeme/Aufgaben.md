## Übung 1.1

### a)

Computer-orientiert:
- UIs
- Programmierung

Mensch-orientiert
- Medizin-Robotik
- Stimmgesteuerte Assistenz-Roboter

### b)

- Sehsinn sehr gut unterstützt über UIs
- Hörsinn sehr gut unterstützt über Tonausgabe
- Tastsinn selten unterstützt
- Geschmack-, Geruchssinn fast nie unterstützt
- Berührungen und Habtik meistens unterstützt, oft aber indirekt (über z.B. Tastaturen)

### c)

- Barrierefreiheit

## Übung 1.? - Merkmale von Bildschirmen

- Bildwiederholrate = 25 bis 144Hz
- Helligkeit
- Auflösung = 720p, 1080p, 4K
- Größe
- Farbraumabdeckung
- Kontrast (in Prozent)
- Farbechtheit
- Latenz (in ms)
- Matt bis glänzend
- Seitenverhältnis (Breite zu Höhe (z.b: 4:3))

## Übung 2.2 - Einsatz von Farben

- Emotionen aufbringen / Stimmung machen
- Erinerrungen aufbringen (z.B. Marketing)
- Aufmerksamkeit lenken
- Unterscheidung von Elementen
- Blickführung

## Aufgabe 3.1

### a)

- Perspektive (Größenunterschied, Level of Detail)
- Schattenwurf
- Überlappung/Überdeckung
- Stereoskopisches Sehen (2 Augen)
- Glanzlicht
- Schattierung
- Parallax Effekt (Nähere Objekte bewegen sich schneller)
- Farbgradienten (Blaustisch und niedrigerer Kontrast auf große Entfernung)
- Tiefenschärfe

## Aufgabe 3.2

- Überlappung/Verdeckung
  - Flächen von hinten nach vorne rendern
  - Z-Buffer
- Schatten
  - Offset, Verdoppelung der Fläche
  - Alpha-Blending durch Multiplizieren der Pixel-Werte mit einem Faktor (z.B. 1-alpha)
- Lichteffekte
  - Transparente Bitmap der Lichteffeke drübergelgtund vermischt
- Wissen über Objekte
  - Rendern einer Texture
- Perspektive
  - im einfachsten Fall einfach Divison bei z
  - Bei generellen Fluchtpunkten, müssen Texturen verzerrt werden
  - Pseudo-3d/isometrische Projektion -> Bitmaps können einfach copy-pasted werden
- Unschärfe
  - sehr teuer -> da jeder Pixel mit den Pixeln aus der Umgebung zusammengerecht werden muss
- Gradienten
  - Hintergrund ausgegraut, geringerer Kontrast, geringere Sättigung, Blaustisch

## Aufgabe 4.2

- Fehlermeldungen
  - kurzer Ton
  - fehlklingend (skeuomorph)
- Wndows-Start Sound
- Klick-Geräusche bei Buttons, virtueller Tastatur, etc.
- Klickgeräusche bei Kameras (skeuomorph)
- Immersion bei Videospielen (skeuomorph)
- Papirknüll-Geräusch bei OS-Trashbin

## Aufgabe 4.5

- Informative Sounds
- Hero Sounds bei Erfolgen (rufen Emotionen hervor)
- Sparsamkeit, Angemessenhit & Ästhetik mit Geräuschen
- Keine Eintönigkeit (leicht variierende Geräusche)
- Primäre (vom OS/Device) vs. Sekundäre Geräusche (seltener, für die App individuell)
- skeuomorphe vs abstrakte Geräusche
- Hoch gehende Geräusche klingen nach Aktivierung und andersherum
- Konsistenz (z.B. in einer Tonart bleiben)
- Prinzipien: Informativ, Ehrlich, Reassuring
- "earcon" als akkustisches Gegenstück für Icons

## Aufgabe 6.3 e)

- schnelle, einfache Wechsel der Modi (z.B. über Keyboard Shortcuts)
  - nicht bei Sicherheitsgefährden (z.B. in Admin-Modus wechseln)
- Modi sollten nur wenn notwendig bzw. wirklich sinnvoll eingesetzt werden
- Unterschiedliche Darstellung der Modi
- Möglichst geringe Anzahl von Modi
- Standard-Eingaben sollten über alle Modi gleich bleiben
- Funktionen sind logisch in Modi aufgeteilt (um notwendige Moduswechsel zu verringern)

## Aufgabe 7.0 (S. 3)

- Hierarchische Kategorisierung der Einstellungen in Unterpunkte (um UI nicht zu überlasten)
- Allgemeine Erklärung der Einstellungen in Text
- Visualisierung potenzieller Einstellungen
- Beispielhafte Nutzung erklärt
- Verlinkung zu Zusatzinformationen (UI nich überlastet und trotzdem alle Infos angeboten)
- Direkte Preview der geänderten Einstellungen
- "Restore Defaults" Option
- Automatische Wahl der Software
- User-spezifische Einstellungsmöglichkeiten (Experte, Amateur, etc.)
- Einstellungen mit Verben beschreiben (Bsp.: "Adjust image settings" statt "Image settings")
- Ausgrauen der Elemente, die zum Moment nicht relevant sind (Infos nicht verbergen, aber Handlungsspielraum einschränken)
- Kontext-/Zusatzinformationen (Bsp.: "System Informations")

## Aufgabe 7.2

- Grid Snapping (x' = (int)(x/dx + 0.5)*dx)
- Verschieben auf einer einzelnen Achse, wenn auf einer Kante angefasst wird (Reduktion auf einer Dimension)
- Live-Verschiebung
- Undo/Redo
- Koordinaten-Anzeige
- Anpassung der Bewegungsgranularität
  - Intelligente Anpassung der Granularität (bei langsamer Bewegung in kurzer Distanz z.B. Granularität erhöhen)
- Gruppierung der Elemente (Grid-Locking relativ zu anderen Elementen)
- Auto-Layout/Template

## Extras on Demand (Hick's Law)

'Länge der Entscheidung wächst logarithmisch zur Anzahl der Wahl-Elemente'

trifft bei UIs nur zu, wenn die Elemente auch sortiert geordnet ist, da sonst keine Binärsuche möglich ist.

## Aufgabe 7.6 a)

1. Nutzer-Rollen definieren (z.B. Designer, BWLer, Profis, Amateuere, etc.)
2. Anwendungsfall/Userflow pro Nutzer-Rolle erstellen
3. Endgeräte definieren
4. Modi definieren
5. Mock-Ups, Konzeption (Layout pro Modus z.B.)
