## Wdh. Verständnisfragen

-   Trennung von operativen & Auswertungsdaten - warum?
    -   Echtzeitdaten werden im Moment genutzt, Auswertungsdaten müssen dagegen erstmal aufebreitet werden
-   4 Bereiche, die Interesse an einem OLAP haben
    -   Marketing
    -   Supply-Chain-Management
    -   Vertrieb
    -   ...
-   Zwei Vertriebsstellen mit überschneidenden Rechnungskreisen benötigen ein gemeinsames OLAP -> Empfehlung?
    -   Hilfsdaten anlegen, um Daten im OLAP zu trennen
    -   oder in zwei Datensätze trennen
    -   oder nur gemeinsame Analyse anbieten
-   Pharmakonzern bietet hohe Summen für Ihre medizinische Labordaten - was ist zu beachten?
    -   Anonymisierung der Daten (teilweise nicht möglich -> sehr vorsichtig sein)
-   Korellation zwischen Schlachtungen in dt. Schlachthöfen un Sitzplatzkapazität der österreichischen Kinos. Was ist daraus abzuleiten?
    -   Erstmal nichts
    -   Man könnte weiter suchen, um zu schauen, ob es eine Kausalität gibt

## Wdh.

-   nur im Datenwürfel sind Messdaten -> in den Dimensionen sind (i.d.R.) keine Messdaten
-   Dimensionen sind immer diskrete Kategorien (z.B. Alter im Sinne von Kind/Teen/Erwachsen/etc.)
-   Ein Faktum ist die genaue Messung, also einfach eine Zahl
-   Im Würfel stehen dann nur die Kategorisierungen der Messungen (nicht die genauen Messungen selbst)
    -   in der Praxis ist das nicht immer so streng getrennt
-   Anders als beim normalen Datenbankmanagement, gibt es bei DWH absichtlich redundante Daten
    -   Hauptgrund dafür ist erhöhte Performanz bei der Datenabfrage
-   Star vs Snowflake Schema (sehr wichtig)

## Datenabfragen

(siehe wunderschöne Folie dazu)

-   Slice = Eine Scheibe des Würfels betrachten (also 2 Dimensionen)
-   Dice = Einen Subwürfel betrachten
-   Drill-Down/-Through/-Up = Überbegriff für tieferes Reingehen/Rausgehen aus den Daten
-   Drill-Across = Zwei Slices/Hierachien miteinander vergleichen
-   Pivot/Rotate = Drehen der Daten, um andere Dimensionen zu betrachten

## Weiteres

-   Transaktionen -> ACID (Atomic, Consistent, Isolated, Durability)
-   CAP (Consistent, Available, Partition tolerance)
    -   Massendatentauglich
    -   Verteilbare Last
    -   Hohe Verfügbarkeit
    -   Konsistenzmanagement ist viel aufwendiger
    -   Schreib-Lese-Konflikte schwieriger zu handhaben
    -   Multiversionen aufwendiger
-   ETL (Extraction, Transformation, Loading)
    -   Extraction
        -   Regelmäßige Extraktion von Daten aus unterschiedlichsten Quellen
        -   Delta-Extraktion (Nur Veränderungen werden im DWH gespeichert)
    -   Transformation
        -   Vereinheitlichung der Datenformate
        -   Daten aus unterschiedliche Quellen zusammenführen
        -   Duplikate entfernen
    -   Loading
        -   Laden der Daten; Pufferung möglich
