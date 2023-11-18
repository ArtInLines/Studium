- 30min zu spät, habe den Anfang verpasst
- Data-Marts (ab S.66 auf den Folien)
- Externe Datenhaltung (Dateien, Datenbanken, Web-Service)
  - Antwort auf meine Frage warum Web-Services, da diese ja an sich auch nur die Daten in Dateien oder Datenbanken speichern:
  - Die interne Struktur der extern gehaltenen Daten kann geändert werden, ohne dass die API-Aufrufe für den Web-Service geändert werden müssen
- Lösung zu Aufgaben auf S. 76:
  1. Frage:
     - Data Lake ist flexibler -> sinnvoll falls das Unternehmen viele unstrukturierte und breit aufgestellte Daten hat
     - Data Mart -> gut wenn die Außenstellen oft unterschiedliche Daten brauchen (die Daten also besser gesplitet werden können) & die Daten besser strukturiert sind
     - MOLAP wäre legitim für Data-Mart, da MOLAPs aber oft teuer sind, wäre es womöglich zu teuer wenn es mehrfach repliziert werden muss in den Data Marts
  2. Frage:
     - Egal welche Antwort, die Begründung ist hier wichtig (es gibt keine allgemein richtige Antwort)
     - klang als könnte so eine Frage auch in der Klausur kommen :(

Kapitel 3: (ab S. 78)
- siehe Folien
1. Frage:
  - Fehlende Parallelisierung
2. Frage:
  - unstruktierte Daten benötigen viele Berechnungen zum Analysieren und Finden von Daten -> braucht viel Energie
3. Frage:
  - Bsp: Daten wurden absichtlich in die USA geschickt
  - Für mehr Beispiele siehe: https://www.dsgvo-portal.de/dsgvo-bussgeld-datenbank/
4. Frage:
  - siehe Folien direkt davor

Kapitel 4: (ab S. 93)
- Data Vault Modell:
  - Hubs sind die zentralen Informationsdaten. Darf mit mehreren Sateliten und Links verbunden sein
  - Sateliten speichern Attribute der Hubs. Sateliten dürfen nicht mit weiteren Sateliten verbunden sein.
  - Links stellen Beziehungen zwischen Hubs und Sateliten dar
- Bilder ab Folie 94 vertauschen Hubs und Links (Korrektur folgt am Wochenende) (siehe bessers Beispiel auf Wikipedia: https://en.wikipedia.org/wiki/Data_vault_modeling)
-