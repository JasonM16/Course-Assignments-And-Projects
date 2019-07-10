Comment !
Project		: Assignment 5
Author		: Jason Choquette
Student ID	: 104 337 378
Date		: 03/19/18
!

TITLE	Assignment 5		(Ass5-Q3.asm) 
INCLUDE Irvine32.inc

.data
k				= 10					
fib_arr			DWORD k DUP(0)
n				DWORD k
value			DWORD 0
displayMsg		BYTE "Fibonacci sequence with N = ", 0
is				BYTE " is: ",0
space			BYTE " ", 0
fibOpen			BYTE "Fib(", 0
fibClose		BYTE ") is: ",0


.code
main PROC	
	push		n				; calculate the nth fib	
	call		fib				; calculate fib (eax)	
	call		DisplaySequence
	call		WaitMsg
	exit
main ENDP






DisplaySequence PROC

call			Crlf	
mov				edx, OFFSET fibOpen
call			WriteString
mov				eax, k
call			WriteDec
mov				edx, OFFSET fibClose
call			WriteString
mov				eax, value
call			WriteDec
call			Crlf	
call			Crlf	

mov				edx, OFFSET displayMsg
call			 WriteString
mov				eax, k
call			WriteDec
mov				edx, OFFSET is
call			WriteString


mov				ecx, k
mov				edi, 4
mov				edx, OFFSET space

mov				eax, 0					; print '0' as first fib number
call			 WriteDec
call			WriteString			; print space

L1:
	mov			eax, fib_arr[edi]
	call		WriteDec
	call		WriteString
	add			edi, TYPE fib_arr
loop L1

call			Crlf
call			Crlf

ret

DisplaySequence ENDP




fib PROC 
	push		ebp
	mov			ebp, esp	
	push		esi	

	cmp			DWORD PTR [ebp+8], 1		; if N <= 1, return n;
	jg			Recurse 

	mov			eax, DWORD PTR [ebp+8]
	mov			DWORD PTR value, eax
	jmp			CopyToArray

Recurse:
	mov			eax, DWORD PTR [ebp+8]
	dec			eax
	push		eax							; (n-1)
	call		fib
	pop			ecx
	mov			esi, eax
	mov			eax, DWORD PTR [ebp+8]
	dec			eax
	dec			eax
	push		eax							; (n-2)
	call		fib
	pop			ecx
	add			esi, eax					; ESI = Fib(n-1) + Fib(n-2)
	mov			DWORD PTR value, esi		; store result in value

CopyToArray:
	mov			eax, DWORD PTR [ebp+8]
	mov			ecx, DWORD PTR value
	mov			DWORD PTR fib_arr[eax*4], ecx
	mov			eax, DWORD PTR value

Done:		
	pop			esi			
	mov			esp, ebp
	pop			ebp
	ret			0

fib ENDP


END main   