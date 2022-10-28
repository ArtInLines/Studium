org 0x100	; Beginne Program bei Adresse 100H
bits 16		; 32-Bit Program
		; SMALL beinhaltet hier nur Code-Segment
SECTION  .CODE
				; Wichtig: Bei Assembler muss ein H ans Ende von Zahlen, um hex-Zahlen zu verwenden
                           	; M1:	; Anfangs-Label
M1:		mov ah,2H	;  Funktionsnummer für Bildschirmausgabe
		mov dl,'4'
LOOP:		int 21H
		inc dl
		cmp dl,'7'
		je END
		jmp LOOP
END:		mov ah,4cH
		int 21H