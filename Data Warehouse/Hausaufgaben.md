## S. 56

### 1.

Sie sollen ein OLAP System konzipieren, um die Konzernumsätze eines Handelskonzerns mit 1.000 Filialen Weltweit und einem Warenangebot von 1.000.000 unterschiedlicher Produkten auzuwerten.
Welches logische Datenmodell wählen Sie und warum?

- ROLAP
- große Datenmengen
- Daten höchstwahrscheinlich strukturierbar
- Unklar ob Daten sehr mehrdimensional sind (dann vllt HOLAP)

### 2.

Die File-Server eines Dax-Konzerns sollen auf verborgene diskriminierende Inhalte hin permanent durchsucht werden.
Welches logische Datenmodell wählen Sie und warum?

- Data Lake
- unstrukturierte Daten
- Suhe via Regex sehr sinnvoll

### 3.

Sie erhalten große Excel Dateien von Umsatzzahlen eines Warenhauses. Daraus sollen sie die Anteile von Warengruppen am jeweiligen Tagesumsatz ermitteln.
Welches logische Datenmodell wählen Sie und warum?

- ROLAP
- Excel ist bereits ein relationales Format
- Große Datenmenge
- Wenn es eine einmalige Aufgabe ist, lohnt sich ein DOLAP (weniger Aufwand)

## S. 58

(siehe Papier)

## S. 63

### 1.

In einer Versicherung soll ein OLAP aufgebaut werden. Dabei soll analysiert werden, welche Streuung der Zeitverzögerung zwischen Datenstand und Datenmeldung liegen.
Welche Form der Temporealisierung empfehlen Sie und warum?

- 2D, da wir wissen wollen seit wann Kenntniss der Daten existiert

### 2.

Ein Textilhandel hat seine Produktgruppen neu sortiert. Dies soll in Ihrem OLAP System nachgepflegt werden und dabei die alte Struktur für Bestandsdaten erhalten bleiben. Begründen Sie Ihr Vorgehen.

- Annahme: Daten sind bereits in einem ROLAP
- Transformieren der Daten in Master-Slave Tabellen, um zukunftssichere Versionierung zu erhalten
- Master-Tabelle enthält neue Version (vereinfacht Nutzung mit aktuellen Daten)
- alte Bestanddaten können über Slave-Tabellen zugegriffen werden

### 3.

Entwerfen Sie eine Faktentabelle für Produkte mit Umsatz und Tagesbezug. Wie können sie diese Umsätze Tagesgenau Temporealisieren?

- Gültigkeitszeitraum mit abspeichern
- Keine Ahnung wie di Faktentabelle aussehen sollte
