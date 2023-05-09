## Übung

-   wird per Email geschickt
-   wir müssen das Excel-Sheet ausfüllen

## Arten an Befehlen

-   Data Movement
    -   bewegt Daten ohn Flagregister zu beeinflussen
-   Stack Manipulation
-   Arithmetic & Logic Befehle
-   Conversions
-   Control Flow
-   String Manipulation
-   Flag Manipulation
-   I/O
-   Protected Mode
-   Floating Point
-   SIMD
-   AES (Advanced Encryption Standard)
-   MPX (Memory Protecton Extensions)
    -   prevent errors such as buffer overflows
-   SMX (Safer Mode Extensions)
-   TSX (Transaction Syncrhonization Extensions)
    -   fpr multitreaded execution
-   VMX (Virtual Machine Extensions)
    -   more secure & efficient for virtualized operating systems
-   etc.

-   Viele dieser Befehler existieren nur bei CISC chips
-   RISC chips dagegen haben meist nur 4 Arten an Befehlen (arithmetic-logical, control flow, memory access, miscellanous)

## RISC

-   see [Design and Implementation of RISC I](./Design%20and%20Implementatn%20of%20RISC%201.pdf) for more info
-   RISC fokussiert Befehle, die auf dem Chip direkt ausgeführt werden können (i.e. Register-to-Register), um das Bandwidth Bottleneck so gut möglich zu umgehen
-   Da RSIC weniger Befehle hat, müssen komplexere Befehle als Subroutinen implementiert werden
    -   d.h. es gibt mehr Procedure Calls bei RISC chips, weshalb Procedure Calls meist optimiert sind bei RISC chips
-   heutzutage gibt es RISC-V, was sehr populär ist
-   Flaches Speichermodell & damit simple Adressierung (kein offset wie bei alten CPUs)

### 32-bit ARM

-   Auch Stack-/Instruction-Pointer etc. ist ein Register
-   nur 16 Register
