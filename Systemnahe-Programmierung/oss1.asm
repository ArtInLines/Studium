org 0x100	; Beginne Program bei Adresse 100H
bits 16		; 32-Bit Program
		; SMALL beinhaltet hier nur Code-Segment
SECTION  .CODE
				; Wichtig: Bei Assembler muss ein H ans Ende von Zahlen, um hex-Zahlen zu verwenden
                           	; M1:	; Anfangs-Label
M1:		MOV AH,08H	; liest Zeichen von Tastatur ohne Bildschirmecho
		INT 21H		; allgemeiner Interrupt
                CMP AL,1BH	; vergleiche Inhalt von AL mit ESC-Taste
                JE ENDE		; wenn gleich, dann springe zu ENDE-LABEL
		MOV DL,AL       ; bringe Eingabe-Zeichen ins rechte Daten-Byte
		MOV AH,2        ; Funktionsnummer für Bildschirmausgabe
		INT 21H		; allg. Interrupt
		JMP short M1 	; unbedingter Sprung zum M1-Label
ENDE:				; ENDE-Label
                MOV AH,4CH	; Funktionsnummer „zurück zu DOS“
                INT 21H		; allg. Interrupt
