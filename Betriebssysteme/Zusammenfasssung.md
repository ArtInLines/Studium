## 1. Prozesse, Threads & Scheduling

### Prozess

- ist ein Programm in Ausführung
- Betriebssystem ist als Menge von Prozessen organisiert (Prozesstabelle)
- Einheit der Ressourcenverwaltung
- Elemente pro Prozess:
    - logischer Adressraum
    - Globale Variablen
    - Geöffnete Dateien
    - Kindprozesse
    - Ausstehende Signale & Signalroutinen
    - Verwaltungsinformationen
    - Zustand (Running, Blocked, Ready)
- Scheduler schaltet zwischen Prozessen für Quasi-Parallelität
- Unterschiedliche Prozesse können auch ohne Problem auf unterschiedlichen Kernen laufen

### Threads

- "Mini-Prozess": mehrere Threads können (quasi-)parallel auf einem Prozess ausgeführt werden
- Threads teilen sich den Adressraums des Mutter-Prozesses
- Einheit der Prozessorzuteilung
- Elemente pro Thread:
    - Befehlszähler
    - Register
    - Stack
    - Zustand (Running, Blocked, Ready)
- Threads können im Benutzer- oder Kernadressraum verwaltet werden
    - im Benutzeradressraum:
        - Prozess verwaltet Threads selbst (eigener Scheduler etc.)
        - funktioniert auch wenn Betriebssystem keine Threads kennt
        - schnellerer Thread-Wechsel, da kein Sprung in Kern nötig ist
        - blockierende Systemaufrufe kann ganzen Prozess blockieren (z.B. bei Page-Fault)
    - im Kernadressraum (gängiger):
        - Kern verwaltet eine Thread-Tabelle für alle Threads
        - Betriebssystem kann bei blockierenden Systemaufrufen Thread wechseln
        - höhere Kosten bei Threadwechsel (erst Sprung in Kern)

### Race Conditions

- Prozesse/Threads wollen gleichzeitig auf die selbe Ressource zugreifen
- Kritische Regionen = Teile des Programms (bzw. des Speichers), in denen auf gemeinsam genutzte Ressourcen zugegriffen wird
- Wechselseitiger Ausschluss
    - Bedingungen
        - Max. 1 Prozess darf gleichzeitig in kritischer Region sein
        - Geschwindigkeit / Anzahl der CPU muss ignoriert werden
        - Prozesse außerhalb der kritischen Regionen dürfen andere Prozesse nicht blockieren
        - Prozesse müssen in endlicher Zeit in kritische Region kommen können
    - Verfahren: Interrupts ausschalten
        - Prozess in kritischer Region schaltet Interrupts aus (auch Timerinterrupt)
        - kein anderer Prozess kann ausgeführt werden, während der Prozess in der kritischen Region ist
        - funktioniert nicht bei Multi-Core-Processors
        - I/O ist blockiert
        - 
    - Verfahren: Sperrvariable
        - 
    - Verfahren: Strikter Wechsel
    - Verfahren: Lösung von Peterson















