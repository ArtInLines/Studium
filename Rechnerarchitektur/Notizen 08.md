-   Floating-Point Zahlen:
    1. Vorzeichen (1 Bit)
    2. Exponent
    3. Fraction
-   Multitasking
-   Kernelmode
    -   Kernel-Mode: Ring 0
    -   User-Mode Ring 1-3
    -   Betriebssystem läuft auf Ring 0
    -   Anwendungen meist in Ring 3
    -   Großrechner haben teilweise unterschiedliche Register für Betriebssystem & User-Mode-Anwendungen
-   Hyperthreading
    -   Threading echt parallel auf der CPU
    -   wird implementiert über mehrere Pipelines, ALUs/FPUs & Registersätze
-   AES
    -   CPUs bieten heutzutage oft native Befehle, um AES-Verschlüsselung zu nutzen
    -   symmetrische Verschlüsselung = 1 einziger Schlüssel (der von beiden Seiten geheim bekannt sein muss)
    -   asymmetrische Verschlüsselung = 1 public & 1 private Schlüssel
    -   symmetrisch ist schneller, aber damit beide Seiten den Schlüssel kennen, wird oft erstmal assymetrische Verschlüsselung verwendet
