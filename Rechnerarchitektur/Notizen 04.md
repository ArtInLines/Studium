## Adressbefehle

-   0-Adressbefehle / Stack
-   1-Adressbefehle / Accumulator
    -   Ergebnisse werden in Zwischenregister gespeichert
-   2-Adressbefehle / CISC
    -   viele spezifische Register
    -   unterschiedlich lange Register
-   3-Adressbefehle / RISC
    -   v.a. generelle Register
    -   alle Register haben gleiche Länge

## Instruction Sets

-   CISC = Complex Instruction Set Computing
    -   große Instruction-Sets (bis zu 1000 Befehle)
    -   4 Arten an Befehlen:
    -   Transport => I/O, Read/Write für Register & Memory
    -   Verarbeitung => ADD, SUB, etc.
    -   Steuerung => Jumps, etc.
    -   CPU Steuerung => Halt, Interrupt, etc.
-   RISC = Reduced Instruction Set Computing
    -   heutzutage dominant
    -   oft schnellere Ausführung der Befehle
        -   v.a. durch CPU-Pipelining, weil die nächsten Befehle gut vorhersehbar sind
    -   Feste Registerlänge
    -   RISC-CPUs haben oft Floating-Point-Units direkt eingebunden
    -   heutzutage gibt es auch umfangreichere, komplexe Befehle
-   VLIW = Very Long Instruction Word
-   EPIC = Exlicitly Parallel Instruction Computing

## Arbeit einer CPU

1. Fetch Instruction (Datenbus)
2. Decode Instruction ()
3. Execute (ALU)
4. Write (Register/Memory/etc.)

## Registers

-   Data Register
-   Flag Register (z.B. Carry-/Zero-Flag)
-   Pointer/Adress Register

    -   Program/Instruction Pointer
    -   Stack Pointer
    -   Index Register

-   Immediate Adressing
    -   lädt compile-time-known Wert
-   Direct Adressing
    -   lädt die absolute Speicher-Adresse
-   Extended Adressing
    -   Zugriff auf Adresse
-   Indirect Adressing
    -   (siehe Folien)
-   Indexed Adressing
-   Based Indexed Adressing
-   Based Indexed Adressing with Scaling

## Stack

-   PUSH
-   POP
-   PEEK
-   ggf. weitere Befehel
-   wird v.a. bei Suboutinen verwendet

## Interrupt

-   Interrupt-Leitung + -Controller
-   2 Arten von Interrupts
    -   Maskable (kann nicht unterdrückt werden vom Programm)
    -   Non-Maskable (kann vom Programm unterdrückt werden)
-   Interrupt Handling
    -   i.d.R. werden Register, Pointer etc. auf Stack gespeichert
    -   Interrupt Vektor wird aufgerufen (spezieller Speicherbereich für Handling des Interrupts)
    -   Register, Pointer etc. werden wieder hergestellt

## Caches

-   Fully Associative Caches
    -   sehr schnell
    -   braucht viele Register -> teuer & braucht viel Platz
    -   wird v.a. bei L1-Caches verwendet
    -   Mehrere Bytes werden zusammen in Blöcken gespeichert
-   Direct Mapped Caches
    -   speichert einzelne Lines
-   Set Associative Caches

    -   speichert mehrere Lines zusammen
    -   wird v.a. bei L2-3 Caches verwendet

-   i.d.R. 4 Flags
-   T = Type (Data or Instruction)
-   V = Valid (noch gültig?)
-   L = Lock (für Write & Flushing gesperrt?)
-   D = Dirty (müssen noch mit RAM synchronisiert werden)

-   Bei Split-Cache (Data & Instruction separat gespeichert) ist T Flag unnötig
-   Bei Instruction-Cache is D Flag unnötig

-   Deshalb ist Alignment der Daten wichtig für Performance
-   Deshalb ist Data-Locality zusammen-verwendeter Daten wichtig für Performance

## Pipeline

-   Das Fetchen/Dekodieren/etc. des nächsten Befehls fängt an während der jetzige Befehl noch ausgeführt wird
-   Performance-Gain

-   3 Arten an potentiellen Problemen

    -   Strukturkonflikte
        -   externe Hardware (z.B.: FPU (Floating Point Unit)) wird von beiden Befehlen verwendet, braucht aber länger
    -   Datenkonflikte
        -   Befehl 2 braucht Ergebnis von Befehl 1
    -   Steuerungskonflikte
        -   Jumps, Branches können verändern, welcher Befehl als nächstes gebraucht wird
        -   Branch-Prediction vermeidet das Problem (aber nur zu Teilen)

-   RAR (Read-After-Read)
    -   kein Problem, da der gelesene Wert unverändert bleibt
-   RAW (Read-After-Write)
    -   Folgebefehl muss pausiert werden, bis der erste Befehl fertig ist (Pipeline pausiert)
    -   ideal Case: Compiler erkennt das und führt 1-2 andere Befehl zwischendurch aus
-   WAR (Write-After-Read)
    -   Mögliches Problem: Schreiben ist fertig bevor das Lesen anfängt (v.a. bei Parallelisierung oder Nutzung externer Hardware (z.B. FPU))
-   WAW (Write-After-Write)

    -   Mögliches Problem: 2. Befehl ist fertig bevor 1. Befehl fertig ist (v.a. bei Parallelisierung oder Nutzung externer Hardware (z.B. FPU))
