## Warum Datenbanken-Systemen?

-   **Redundanz und Inkonsistenz**
-   **Probleme beim Mehrbenutzerbetrieb**
-   _Verlust von Daten_
-   _Integritätsverletzung_
-   Beschränkte Zugriffsmöglichkeiten
-   Sicherheitsprobleme
-   hohe Entwicklungskosten für Anwendungsprogramme

## Daten

-   DDC = ???
-   DML = Data-Manipulation-Language

## Architektur eines DBMS

![Kapitel1 S. 16](assets/screenshot_1.png)

## Übungen

1. Können Sie sich eine sinnvolle Einsatzmöglichkeit für eine durch DBMS kontrollierte Redundanz vorstellen?
    - Höhere Performanz (ähnliches Prinzip wie beim Caching) v.a. bei komplexeren Anfragen
2. ...
3. Konzipieren Sie ein Wahlinformationssystem für Bundestagswahlen (zu verwaltende Daten? Probleme ohne DBMS?)
    - Daten:
        - Wähler:innen
        - Wahlkreise
        - Zur Wahl aufgestellte Personen
    - Mögiche Probleme:
        - Problem bei z.B. gleichen Namen
        - Inkosistenz
        - Viele Daten lassen sich von einander berechnen (z.B. Gesamtzahl aller Wähler:innen)
        - Redundanzen (Aufgestellte Personen von Partei x und allgemein alle aufgestellten Personen)
