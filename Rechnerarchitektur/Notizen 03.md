-   ROM = Read-Only-Memory
    -   Heutzutage seltener
-   PROM = Programmable ROM
-   EPROM = Erasable PROM
    -   Daten können mit starkem UV-Licht gelöscht werden
-   EEPROM = Electrically EPROM
    -   Daten können Bit-weise elektrisch gelöscht werden
-   Flash-Speicher
    -   lässt sich schnell in Blöcken auslesen
    -   modernere Alternative zu EEPROM
    -   begrenzte Lebensdauer
    -   NAND-Flash-Speicher -> nicht linear adressierbarer Speicher
    -   NOR-Flash-Speicher -> linear addressierbarer Speicher
-   PLD = Programmable Logic Device
    -   spielenheute keine Rolle mehr
-   PAL = Programmable Arrays Logic
    -   können nur einmal programmiert wrden
-   GAL = Generaic Arrays Logic
    -   kann umbeschrieben werden
-   CPLD = Complex Programmable Logic Device
-   FPGA = Field Programmable Gate Array
    -   komplexe Schaltung als Hardware

Diese programmierbaren Chips erlauben die Erstellung von Automaten, die über unterschiedliche Wege angesprochen werden können.

Von Maximilian Koch:

> Am Schluss sind das was man da programmiert ist die Aussteuerung der Transistoren (Gates), die den Algorithmus denn man haben möchte, direkt in Hardware gießt und wird dann von solchen ASIC Herstellern gefertig. (Die Erstellung der Logic Arrays macht heute die Software der Hersteller). Über die von dir definierten Pins, an der Schaltung bzw. den Bus den definiert hast du Input und Output via elektromischen Signalen, die du dann meist in ein SoC oder an einer andere Art von generell purpose CPU anbindest.

-   RAM = Random Access Memory
    -   schnell
    -   flüchtiger Speicher (Daten weg, wenn Strom ausgeht)
    -   statischer vs. dynamischer RAM (SRAM vs DRAM)
        -   statisch ist schneller aber komplizierter & teurer
    -   bei SRAM kann die Adresse direkt übertragen werden
    -   bei DRAM muss die Zeile erst aktiviert werden, deshalb ist das Ansprechen der RAM-Zelle in zwei Teile geteilet - erst Zeile aktivieren - dann Spalte auslesen
-   Kondensator
    -   (siehe Folie dazu)
-   RAM-Zelle

    -   (siehe Folie dazu)

-   DRAM hat einen Kondensator

    -   verliert jederzeit ein wenig Spannung, weswegen er immer wieder refresht werden muss
    -   beim Auslesen verliert er alle Spannung, weswegen der gelesene Wert wieder zurückgeschrieben werden muss

-   Memory Interleaving

    -   DRAM wird in 2+ Speicherbänke geteilt
    -   Dadurch kann das Auslesen von Daten bis zu verdoppelt werden
    -   z.B. gerade Adressen werde in Bank 1 gespeichert, ungerade Adressen werden in Bank 2 gespeichert
    -   Memory Controller kümmert sich um Memory Interleaving

-   SDRAM = Synchronous DRAM
-   DDR RAM (Double Data Rate)
    -   Bei DDR1 werden Bits bei auf- & absteigender Spannung übertragen
    -   Bei DDR5 gibt es bereits 16 Bits pro Flanke
    -   DDR ist damit sehr viel schneller
    -   DDR5 hat auch mehr Zeit zwischen Refreshes
-   Kennwerte bei RAM

    -   tCL = Column Access Strobe Latency
        -   Senden des Befehls an Speicher & Beginn der Antwort
    -   tRP = RAS precharge
        -   Minimale Zeit um auf de nächste Zelle zuzugreifen
    -   tRCD = RAS-to-CAS
        -   Zeit um Speicher auszulesen
    -   tRAS = Row Active Time
        -   Zeit um Daten in Ausgangspuffer vorzulegen, um auf Daten zuzugreifen
    -   Kühlung ist bei RAM-Chips sehr wichtig
    -   CPU-Caches macht RAM-Geschwindigkeit etwas unwichtiger

-   ECC = Error Correction Codes
    -   i.d.R. via Hamming Codes
    -   meist können Fehler von einem einzelnen Bit korrigiert & von 1-2 Bits erkannt werden
-   SRAM = Static RAM
    -   besteht i.d.R. aus 6 Transistoren (DRAM dagegen nur 1 Transistor)
    -   sehr viel schneller
    -   meist in Caches, Buffer, etc. zu finden
-   Caches
    -   L1 Cache (schnelle Flip Flops, die in einem Zyklus antworten können)
        -   oft in L1I & L1D geteilt (Instruction & Data Cache)
    -   L2 Cache (SRAM)
    -   L3 Cache
    -   L4 Cache (noch sehr selten)
    -   inklusiv
        -   Alle Daten in Lx sind auch in allen größeren Caches
    -   exklusiv
        -   Alle Daten sind nur in einem einzelnen Cache
    -   Multicore-Prozessoren verkomplizieren Caches
        -   L1 pro Core
        -   L2 unterschiedlich behandelt
        -   L3 für alle Cores
    -   Kennwerte:
        -   Hit-Rate
        -   Miss-Rate
            -   Capacity Miss
            -   Conflict
            -   Cold Start Miss (Compulsory)
    -   Write-Through (Direkt auf Speichermedium schreiben)
    -   Write-Back (Hält Daten erstmal nur im Cache)
    -   Verdrängungsverfahren
        -   FIFO (First-In-First-Out)
        -   LRU (Least Recently Used)
        -   LFU (Least Frequently Used)
        -   Random (geringer Stromverbrauch)
        -   CLOCK (wird nach Miss & Zeitwert bewertet - effektiv aber energieverbrauchend)
        -   Statistik (Logik innerhalb des Caches - effektiv aber komplexer & teurer)
-   Memory Controller
    -   überwacht dass nur eine Fnktionseinheit schrebt/ließt
    -   read/write von RAM
    -   steuert Refreshes des RAMs
    -   Managing von DMA, damit mit anderen EInheiten & CPU keine Kollisionen entstehen
    -   ECC Auswertung
    -   heute i.d.R. in CPU integriert
-   DMA Controller (Direct Memory Access)
-
