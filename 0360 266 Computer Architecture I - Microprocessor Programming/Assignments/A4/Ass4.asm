Comment !
Project		: Assignment 4
Author		: Jason Choquette
Student ID	: 104 337 378
Date		: 03/09/18
!

TITLE	Assignment 4		(Ass4.asm) 
INCLUDE Irvine32.inc

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;  BEGIN .data  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
.data
counter			DWORD 0
hStringOutput	BYTE  10 DUP(?) ; 8 characters plus h and null terminator
hStringInput	BYTE  10 DUP(?) ; 8 characters plus h and null terminator

hexValues		BYTE  '0', '1', '2', '3', '4', '5', '6', '7','8', '9',
					  'A', 'B', 'C', 'D', 'E', 'F'

charValues	    WORD  30h,  31h,  32h,  33h,  34h,  35h,  36h,  37h, 38h,  39h,
				      41h,  42h,  43h,  44h,  45h,  46h

menuString		BYTE "What do you want to do?", 0dh,0ah
				BYTE "W. Call HexOutput procedure.", 0dh,0ah
				BYTE "R. Call HexInput procedure.", 0dh,0ah,0
							
getLost			BYTE "Get Lost Sweetey Honey Bun.",0
thankYou		BYTE "Thank you Sweetey Honey Bun.",0	

iInput			BYTE "Enter 32-bit unisigned integer: ",0
hInput			BYTE "Enter hexadecimal string: ",0

hOutput			BYTE "Hexadecimal value: ", 0
bOutput			BYTE "Binary value: ", 0
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;  END .data  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

.code
;-----------------------------------------------
main PROC


mov edx, OFFSET menuString				; load menu options
call WriteString						; show menu options
call ReadChar							; get user input
call Crlf


.IF (al == 'W' || al == 'w')	
	mov edx, OFFSET iInput
	call WriteString	
	call HexOutput						; convert number and print to console
	mov edx, OFFSET thankYou			;  thank you exit message

.ELSEIF	(al == 'R' || al == 'r')
	mov edx, OFFSET hInput
	call WriteString
	call HexInput						; convert number and print to console
	mov edx, OFFSET thankYou			; thank you exit message

.ELSE
	mov edx, OFFSET getLost				; get lost exit message
.ENDIF

call Crlf
call WriteString						; print exit message
exit

main ENDP 







; This procedure takes a char value in hex representation and 
; indexes through an array until a match is found.
; An index is used as a counter and this counter value is 
; and is used as the binary value
; Ex: if the char value 'E' (45h) is in bx, search the charValues
; array for 45h. When 45h is found the counter value is 14. This is 
; the decimal value of the hexadecimal value E.This value is then stored
; in ebx....
Char2Hex PROC
pushad								; save registers
mov ecx, LENGTHOF charValues		; loop counter
mov esi, 0							; array index
mov edx, 0							; use as temp counter
mov counter, 0

	L1:
		.IF bx == charValues[esi]	; found a match, so exit
			jmp end1
		.ENDIF
		
		add esi, 2					; look at next word
		inc edx						; increase coutner
		mov counter, edx			; store counter
	loop L1

	end1:		
		popad						; restore registers
		mov edx, counter			; store counter
		mov bx, dx					; store counter in bx to be used as hex value
	ret

Char2Hex ENDP




HexOutput PROC
call ReadDec						; get integer to be converted
mov ebx, eax						; store value in ebx
mov ecx, 8							; repeat 8 times
mov edi, 0							; use as index

; pseudo-code per lecture notes...
	L1:
		rol ebx, 4
		mov dl, bl
		and dl, 0Fh
		movzx esi, dl
		mov al, hexValues[esi]
		mov hStringOutput[edi], al
		inc edi
	loop L1

	mov hStringOutput[edi], 'h'		; make last element of hex string h
	mov hStringOutput[edi+1], 0		; null-terminate the string

	mov edx, OFFSET hOutput			
	call WriteString
	mov edx, offset hStringOutput	
	call WriteString				; print the result to console as string

ret
HexOutput ENDP




HexInput PROC
mov  edx, OFFSET hStringInput			; point to the buffer
mov  ecx, SIZEOF hStringInput			; specify max characters

call ReadString							; input the string


xor ebx, ebx							; ebx will hold result
mov edi, 0								; use as index
mov eax, 0								; holds numerical value of hexadecimal string

	L1:
		mov bl, hStringInput[edi]					
		.IF hStringInput[edi] != 'h'	; check for the end of the input
			rol eax, 4					; shift a nibble
			inc edi						; move to next char
		.ELSEIF hStringInput[edi] == 'h'
			jmp end1					; end of input, so return										
		.ENDIF	

		call Char2Hex					; returns hex value as int in bl
		and bl, 0fh						; just want the bottom nibble		
		xor al, bl						; xor operation is used as mask to keep top nibble of ax		
	loop L1

	end1:
	mov edx, OFFSET bOutput			
	call WriteString
	call WriteBin						; display the hex representation
	ret
HexInput ENDP


END main  