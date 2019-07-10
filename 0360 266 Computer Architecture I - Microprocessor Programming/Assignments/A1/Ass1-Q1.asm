TITLE  Assignment 1                  (Ass1-Q1.asm)


INCLUDE Irvine32.inc

.data
valA sdword -210
valB sdword +10
valC sdword ?		; C = +3210
valD sdword ?		; D = +43210
valZ sdword ?
getCValue byte  "What is the value of C?  ",0
getDValue byte  "What is the value of D?  ",0
displayExp byte " Z = (A - B) + (C - D)",0
spaces byte    "   :   ",0
finalResult byte "The final result contained in variable Z is: ", 0
binary byte "In Binary: ", 0
decimal byte "In Decimal: ", 0
hex byte "In Hexadecimal: ", 0


.code
main PROC
	
	call Clrscr

	mov edx, offset getCValue	; store string address in edx
	call WriteString			; prompt user for the value of variable C
	call ReadInt				; get the value from the console
	mov valC, eax				; copy value into valC
	

	mov edx, offset getDValue	; store string address in edx
	call WriteString			; prompt user for the value of variable D
	call ReadInt				; get the value from the console
	mov valD, eax				; copy value into valC
	


	mov eax, valA
	sub eax, valB				; eax = A - B
	mov valZ, eax				; Z = (A - B)

	mov eax, valC
	sub eax, valD				; eax = C - D
	add valZ, eax				; Z = (A - B) + (C - D)


	; display string "Z = (A - B) + (C - D)" to the console
	;-------------------------------------------------------------------------
	call Crlf
	mov edx, offset displayExp
	call WriteString
	call Crlf
	call Crlf


	; display the value of each variable to the console
	;-------------------------------------------------------------------------
	mov eax, valA
	call WriteInt
	mov edx, offset spaces
	call WriteString
	mov eax, valB
	call WriteInt
	mov edx, offset spaces
	call WriteString
	mov eax, valC
	call WriteInt
	mov edx, offset spaces
	call WriteString
	mov eax, valD
	call WriteInt
	

	call Crlf
	call Crlf
	mov eax, valZ
	

	; display the final result in each number system to the console
	;-------------------------------------------------------------------------
	mov edx, offset finalResult
	call WriteString
	call Crlf
	call Crlf
	mov edx, offset binary
	call WriteString
	call WriteBin
	call Crlf
	call Crlf

	mov edx, offset decimal
	call WriteString
	call WriteInt
	call Crlf
	call Crlf

	mov edx, offset hex
	call WriteString
	call WriteHex
	call Crlf
	call Crlf

	call WaitMsg
	
	exit
main ENDP
END main  