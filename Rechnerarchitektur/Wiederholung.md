# Klausur

insgesamt 100 Punkte; 50 Minuten
3 Bonusfragen (nicht bei den 100-Punkten dabei) (geben extra Punkte, v.a. sinnvoll wenn man zwischen Noten liegt)
Aufgabe zu Caches, Pipelines (1/3)
Verständnis-Fragen (1/3)
"Was gibt es"-Fragen (1/3) (auch Vor- & Nachteile erwähnen)

beidseitig handschriftliches DIN-A4 Blatt ist erlaubt mitzunehmen

# Notizen der letzten Vorlesung

Für eine (Bonus?-)Aufgabe zu wissen:

-   Unterschiedliche CPUs:

    -   ARM (RISC-basiert)
    -   Sun's Spark (RISC-basiert)
    -   RISC V (mehr oder minder open-source)
    -   moderne Chips von z.B. AMD haben nun oft auch RISC-Kerne

-   Interrupt Handling sollte sich auch auf jeden Fall nochmal angeschaut werden
-   Structure-Alignment ist v.a. für Caching wichtig (dafür sollte es bekannt sein)
-   Caching-Aufgabe ähnlich zu Excel-Aufgabe
-   Pipeline-Stall Aufgabe ähnlich zur Aufgabe in Folien
-   DRAM vs SRAM?
-   Besonderheit von DDR?
    -   Double-Data-Rate + Interleaving
    -   Prefetching wird entsprechend erhöht
    -   speziell DDR5 hat eigenen Spannungsversorgung
-   Hersteller speichern Daten unterschiedlich - welche Arten gibt es da?
    -   Big-Endian & Little-Endian
-   Flip-Flop, Multiplexer etc. kommen in der Klausur nicht dran
-   Eigenheiten der Multiprozessor-Architekturen kommen nicht dran

## Beispielfragen:

-   Wie viele Festplatten braucht man bei RAID 6 min.
    -   4
-   bei RAID 5?
    -   3
-   bei RAID 0?
    -   2
-   Vorteile / Nachteile von RAID 1?
    -   Lesen ist schneller, Schreiben ist langsamer
    -   (gibt noch mehr zu sagen)
-   Welche sind die 2 zentralen Architekturen + Vor-/Nachteile
    -   Von Neumann, Harvard
    -   Bottleneck bei Bus beim Neumann, aber leichter zu implementieren
    -   Segmentierung des Speichers bei Harvard
-   Wie viele Caches gibt es heute?
    -   L1i, L1d, L2, L3 + L4 ist langsam am kommen
    -   L1 ist am kleinsten, dann wird es immer größer
-   Welche 3 Register-Pointer gibt es?
    -   Program Pointer
    -   Stack Pointer
    -   Index Pointer
-   Heap
    -   dynamischer Speicher, der auch verwendet wird, wenn der Programmstatus zwischengespeichert werden muss bei einem Interrupt
-   Welche Protokolle für Anschlüsse an den PC gibt es?
    -   USB, Thunderbolt, RS-232, IIC (Inter-Integrated Circuit), SPI (Serial Periphal Interface)

# Notizen der vorletzten Vorlesung:

-   Von Neumann Architektur
    -   besonders wichtig: gemeinsamer Bus für Code, Data, I/O
    -   alles liegt zusammen im Speicher
-   Harvard Architektur
    -   komplexer aber schneller
    -   seperate Busse für Code, Data, I/O
    -   Speicher ist aufgeteilt in mehrere Segmente
-   Speicher-Hierachie

    1.  Register
    2.  L1-Cache (instruction & data cache) (L1i ist meist größer als L1d)
    3.  L2-Cache
    4.  L3-Cache
    5.  L4-Cache (selten)
    6.  Arbeitsspeicher / RAM
    7.  Festplatte

-   Statischer vs. Dynamischer RAM
    -   SRAM braucht sehr viel mehr Transistoren (teuer, Strom- & Platzverbrauch)
    -   SRAM nimmt die ganze Adresse auf einmal
    -   DRAM nimmt erst die Zeile, aktiviert diese dann & nimmt dann die Spalte
-   DDR
    -   gibt mehrere Daten pro Flanke
-   Prefetch
-   Persistenter Speicher
    -   IOPS sind wichtig
    -   SCSI, SAS, SSD, etc.
    -   RAID-Level
-   Instruction Sets
    -   CISC, RISC, VLIW, EPIC
-   Arbeit einer CPU
    1.  Fetch
    2.  Decode
    3.  Execute
    4.  Write
    -   spezielle Register: Program/Instruction Pointer, Stack Pointer, Index Register
-   Stack / Heap
-   Interrupt
    -   Maskable vs Non-Maskable
    -   Interrupt Handling
-   Arten an Caches
    -   Direct-Mapped Cache
    -   Fully Associative Cache
    -   Set-Associative Cache
-   Flags beim Cache
    -   Type, Valid, Dirty, etc.
-   Alignment für Cache-Lines wichtig
-   Pipeline
    -   RAR, RAW, WAR, WAW
    -   Out-of-Order Execution for Performance-Gains

Historie & welcher Hersteller was gemacht hat ist sinnvoll, aber nicht unbedingt notwendig (gut für Kontext vor allem)
