TITLE  Assignment 1                  (Ass1-Q1.asm)


INCLUDE Irvine32.inc

.data
bigEndian byte ?, ?, ? ,?
littleEndian dword ?

getLittleEndianValue byte  "Enter a value for littleEndian: ",0
comma byte "h, ",0
last  byte "h",0


.code
main PROC
	
	call Clrscr								; clear the screen
	mov ebx, type byte						; define the type to be printed out to console
	; get user input
	mov edx, offset getLittleEndianValue	
	call WriteString						; display message to user
	call ReadHex							; Irvine Procedure:: stores value in eax register
	call Crlf								; new line
	

	;------------------------------------------------------------------------------------
	mov esi, 0		
	mov ecx, LENGTHOF bigEndian		; loop counter
	fillArray:
		mov bigEndian[esi], al
		inc esi
		mov bigEndian[esi], ah
		inc esi
		rol eax, 16	
	loop fillArray
	;------------------------------------------------------------------------------------



	;------------------------------------------------------------------------------------
	mov edi, offset bigEndian		; address of bigEndian
	mov ecx, LENGTHOF bigEndian		; loop counter

	printResults:
				mov al, [edi]	
				add edi, TYPE bigEndian
				call WriteHexB 
				cmp ecx, 1			; don't print comma on last hex digit
				je continue
				mov edx, offset comma
				call WriteString
	loop printResults	
	;------------------------------------------------------------------------------------	



	;------------------------------------------------------------------------------------	
	continue:
	mov edx, offset last	; don't print comma on last hex digit
	call WriteString
	;------------------------------------------------------------------------------------	


	call Crlf
	call WaitMsg
	
	exit
main ENDP
END main  