## Themen für Klausur

- E/R Modellierung
  - UML sollte man lesen können aber muss man nicht schreiben können
  - Entweder Chen oder Min-Max Notation
  1. Konzeptionelles Modell
  2. Logisches Modell
  3. Physisches Modell
- SQL, DDL (Physische Datenmodell)
- Transaktionen, ACID, Recovery, Mehrbenutzer
- Normalisierungen
  - vage Antwort von ihm, aber reicht wahrscheinlich wenn man direkt in 3. Normalform umformen kann (Einzelschritte in 1. und 2. Normalform unwichtig)
- Relationale Algebra

- Query-Optimierung kommt nicht dran
- Regeln von Codd muss man nicht auswendig können
- keine Views

- 2 doppelseitig beschriebene Blätter dürfen mitgenommen werden

## Übung

```SQL
CREATE TABLE STAR
(ID INTEGER, Name VARCHAR(20));
--- Links ----------------------------------- Rechts -----------------------------
INSERT INTO STAR VALUES (3, 'Miley');
											INSERT INTO STAR VALUES (7, 'Billie');
INSERT INTO STAR VALUES (5, 'Taylor');
											SELECT * FROM STAR; -- (1)
COMMIT;
											DELETE FROM STAR;
SELECT * FROM STAR; -- (2)
											ROLLBACK;
											SELECT * FROM STAR; -- (3)
COMMIT;
```
Was sind die Ergebnisse der 3 Select-Statements?
Annahme: Row-Lock, Read-Committed-Isolation

### (1)

Linke Seite hat X-Lock auf einige Rows der Tabelle, Rechte Seite fordert für Select ein S-Lock auf die ganze Tabelle an und deswegen muss es warten, bis die linke Seite das X-Lock über das Commit abgegeben hat. Ergebnis des 1. Select-Statements ist dann:
- Miley
- Taylor
- Billie

### (2)

Das Delete der rechten Seite setzt auf alle Rows in der Tabelle ein X-Lock. Das Select der linken Seite muss dann warten, bis die X-Locks wieder aufgehoben wurden. Das passiert erst beim Rollback. Dann liest das 2. Select-Statement:
- Miley
- Taylor

### (3)

Niemand hält ein X-Lock auf eine der Reihen, deswegen ließt das Select-Statement sofort alle Werte in der Tabelle:
- Miley
- Taylor

## Isolations-Level

- Read Uncommitted
  - Liest auch noch nicht commitete Änderungen
- Read Committed
  - Liest alle Änderungen der eigenen Transaktion sowie alle bereits commiteten Änderungen anderer Transaktionen
- Repeatable Read
  - S-Locks werden wie X-Locks bis Ende der Transaktion gehalten
  - Damit können andere Transaktionen die Rows, die gelesen wurden, nicht verändert werden
  - Verhindert alle Anomalien außer Phantom Reads (sprich weitere Zeilen können inserted werden können)
- Serializable
  - Die ganze Tabelle wird gelockt, damit werden auch Phantom Reads verhindert

## Übung

https://kstbb.de/informatik/rdb/01/1_4_Uebungsaufgaben.html

Lösung: siehe Bild