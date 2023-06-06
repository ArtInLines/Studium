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
    5.  RAM / Hauptspeicher
    6.  Festplatte

-   Statischer vs. Dynamischer RAM
    -   SRAM braucht sehr viel mehr Transistoren (teuer, Strom- & Platzverbrauch)
    -   SRAM nimmt die ganze Adresse auf einmal
    -   DRAM nimmt erst die Zeile, aktiviert diese dann & nimmt dann die Spalte
-   DDR
    -   gibt mehrere Daten pro Flanke
-   Prefetch
-   Arten des persistenten Speichers
    -   IOPS sind wichtig
    -   SCASI, SAS, SSD, etc.
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
    -   Associative Cache
    -   Set-Associative Cache
-   Flags beim Cache
    -   Type, Valid, Dirty, ???
-   Alignment für Cache-Lines wichtig
-   Pipeline
    -   RAR, RAW, WAR, WAW
    -   Out-of-Order Execution for Performance-Gains

Historie & welcher Hersteller was gemacht hat ist sinnvoll, aber nicht unbedingt notwendig (gut für Kontext vor allem)

## Klausur

insgesamt 100 Punkte; 50 Minuten
3 Bonusfragen (nicht bei den 100-Punkten dabei) (geben extra Punkte, v.a. sinnvoll wenn man zwischen Noten liegt)
Aufgabe zu Caches, Pipelines (1/3)
Verständnis-Fragen (1/3)
"Was gibt es"-Fragen (1/3) (auch Vor- & Nachteile erwähnen)

beidseitig beschriebenes DIN-A4 Blatt ist erlaubt mitzunehmen (ob es handschriftlich sein muss, fragt er nochmal nach)
