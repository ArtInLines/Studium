## Von Neumann Architektur

-   Gemeinsamen BUS-System, um auf Speicher zuzugreifen
-   Daten & Code zusammen in Speicher gespeichert
-   Flaschenhals beim Speicher, weil COde & Daten dort zusammen liegen
-   leicht zu bauen

## Harvard Architektur

-   Ein BUS-System für Daten & ein BUS-System für Daten
-   Schneller, weil auf Daten & Code gleichzeitig zugegriffen werden kann
-   komplexer zu bauen
-   wird in bestimmten Bereichen (z.B. Reglungstechnik) verwendet

### Control Unit

-   Verarbeitet Instruktionen synchron
-   Steuert CPU Komponenten an (z.B. ALU)
-   Updatet Counter (PC)

## Motorla Datenblatt

-   Großes Problem bei CPU ist Hitze
    -   deshalb heute häufig quadratische Form
    -   damals trotzdem rechteckige Form
-   Relativ wenige Pins
-   Sieben Adress-Modi
-   TTL (Transistor-Transistor-Logik)
    -   fressen viel Strom
-   damals hatten CPU & RAM oft die selbe Frequenz, heute ist das nicht mehr so
-   A0-Ax = Adress-Bus
-   D0-Dx = Daten-Bus
-   HALT, RESET, et.c sind Steuer-Bus
-   Steuer-Bus & DMA-Controller sprechen den Spicher-Bereich an (ob RAM, Festplatte, etc.)
-   Auf Adress-Bus liegt die Adresse (die angesprochen werden soll)
-   Auf Daten-Bus liegen die Daten (die geschrieben werden / gelesen wurden)
-   Heutzutage sind CPUs sehr viel empfindlicher für die genauen Spannungen
-   Heutzutage haben CPUs zusätzlich noch mehrere Levels an Caches
-   Program Counter => Adresse der derzeitigen Instruktion
-   Stack Pointer =>
-   Index Register => Index of Arrays/Strings/Schleifen

## Intel Datenblatt

-   AD (Adress & Daten) wurden in Demultiplexer weitergegeben
    -   Grund dafür: Der Chip hatte zu wenige Pins für eigene Adress- & Daten-Pins
-   Dynamische RAM nutzen Kondensatoren, welche die Spannung nach einiger Zeit verlieren alle paar Mikrosekunden refresht werden müssen
-   CPU ist heutzutage sehr viel schneller als RAM
