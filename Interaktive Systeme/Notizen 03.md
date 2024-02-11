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



