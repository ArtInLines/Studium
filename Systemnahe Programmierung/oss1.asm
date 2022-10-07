org 0x100                                                
bits 16 				
	
SECTION  .CODE
                                                               ; M1:	; Anfangs-Label
M1:		MOV AH,08H	; liest Zeichen von Tastatur ohne Bildschirmecho
		INT 21H		; allgemeiner Interrupt
                CMP AL,1BH	; vergleiche Inhalt von AL mit ESC-Taste
                JE ENDE	; wenn gleich, dann springe zu ENDE-LABEL
		mov dl,al                  ; bringe Eingabe-Zeichen ins rechte Daten-Byte
		mov ah,2            	; Funktionsnummer für Bildschirmausgabe
		int 21H		; allg. Interrupt
		JMP short M1 		; unbedingter Sprung zum M1-Label
ENDE:				; ENDE-Label
                MOV AH,4CH	; Funktionsnummer „zurück zu DOS“
                Int 21H		; allg. Interrupt
