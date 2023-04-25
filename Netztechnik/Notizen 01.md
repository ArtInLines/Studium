# Fachbegriffe

-   Korrekte Verwendung von Fachbegriffen ist ihm sehr wichtig

## Dienst

-   Datenbasierte abstrakte Funktion, die durch einen Dienstanbieter realisiert wird.
-   I.d.R. zur Unterstützung einer Software-Anwendung.
-   Übertragung läuft über Netzwerke.
-   Zugriffe & Kommunikation laufen über Protokolle.

## Protokoll

-   Kommunikation = Austausch von Nachrichten
-   Protokolle legen zeitliche, syntaktische & semantische Regeln bestimmter Kommunikation fest
-   In unserem Kontext sprechen Programme mit einander

## Client & Server

-   Server ist die laufende Anwendung und stellt den Dienstanbieter
-   Client stellt den Dienstanbieter dar
-   Client & Server nutzen das selbe Protokoll (in der selben Version)

# Architekturen

## Client Server

-   Von Client auf Sever gerichtet
-   Client zu Client Kommunikation findet nicht statt
-   Server ist immer passiv & wartet auf Verbindungsaufbau
-   Client ist aktiv & baut Verbindung auf

-   Für Verbindungsaufbau wird i.d.R. TCP verwendet
-   fast alle Protokolle nutzen dieser Architektur

## Peer to Peer

-   Peer: Gleicher unter Gleichen
-   Keine vorgegebene Kommunikationsrichtung
-   Fundamental dezentral

# Netzwerk-Arten

-   Point-to-Point (Leitungsvermittlung)
    -   exklusive Leitungsverbindung
    -   Bsp.: Telefonnetz mit Leitungsvermittlung
    -   teuer & heute kaum noch verwendet
-   Broadcastnetz (Paketvermittlung)
    -   Datenpakete mischen sich auf dem Weg
    -   jedes Paket muss deshalb Absender & Addressat enthalten
    -   Latenz
    -   bei Leitungsvermittlung nicht bedeutend
        -   an jedem Vermittlungsknoten entsteht eine zusätzliche Wartezeit
        -   die gewählte Route kann schneller/langsamer sein & kann sich auch bei jedem Paket ändern
        -   Auslastung eines Routers kann die Latenz stark beeinflussen (überproportionale Verbindung)
        -   die Latenz kann unendlich groß werden -> Paketverlust
        -   Netzwerke haben i.d.R. eine Auslastungsgrenze von ca. 70%
    -   Latenzschwankungen
    -   keine garantierte Bandbreiten
-   Broadcastnetz
    -   gemeinsames Übertragungsmedium
    -   Problem: mehrere Netzwerksknoten dürfen nicht gleichzeitig Daten senden - sonst gibt es Kollisionen
    -   Bandbreite des Übertragungsmediums muss geteilt werden

## Zugriffsverfahren

Lösungsverfahren für Broadcastnetze, um Kollisionen zu vermeiden:

-   Master-Slave
    -   zentral
    -   Master steuert zentral den Zugang zum Medium für alle Knoten
    -   Bsp.: USB, Bluetooth
    -   könnte man in Computernetzwerken machen, will man aber nicht
        -   Master hat viel Arbeit zu tun
        -   nicht besonders effizient
-   ALOHA
    -   dezentral
    -   deprecated
    -   stochastischer Zugriff
-   CSMA/CD = Carrier Sense, Multiple Access, Collision Detection
    -   dezentral
    -   keine Vermeidung von Kollisionen
    -   löst Kollisionen auf
    -   Auflösung ist performanter als Vermeidung von Kollisionen
    -   etwas aus der Zeit gefallen
-   CSMA/CA = Carrier Sense, Multiple Access, Collision Avoidance
    -   dezentral
    -   vermeidet Kollisionen
    -   wird bei WLAN verwendet
        -   Da Geräte außer Reichweite sein können, kann CSMA/CD bei WLAN nicht genutzt werde
    -   großer Overhead komplexer Protokolle
-   Tokenpassing
    -   zentral/dezentral
    -   Senderecht/Token wird von Station zu Station weitergegeben
    -   Netzwerkgraph ist ringförmig aufgebaut
    -   die Maximal-Latenz ist konstant & proportional zur Anzahl der Netzwerkknoten
    -   Minimale Bandbreite ist garantiert
    -   echtzeitfähiges Netzwerk
    -   ähnliches Zugriffsverfahren wird heutzutage in Autos verwendet
