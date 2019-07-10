Comment !
Project		: Assignment 5
Author		: Jason Choquette
Student ID	: 104 337 378
Date		: 03/16/18
!

TITLE	Assignment 5		(Ass5-Q1.asm) 
INCLUDE Irvine32.inc


.data
resultMsg BYTE "The gcd is: ",0
.code

main PROC
; find gcd(5, 20)
push 5
push 20
call Gcd
mov edx, OFFSET resultMsg
call WriteString
call WriteDec
call Crlf
call Crlf

; find gcd(24, 18)
push 24
push 18
call Gcd
mov edx, OFFSET resultMsg
call WriteString
call WriteDec
call Crlf
call Crlf

; find gcd(11, 7)
push 11
push 7
call Gcd
mov edx, OFFSET resultMsg
call WriteString
call WriteDec
call Crlf
call Crlf

; find gcd(432, 226)
push 432
push 226
call Gcd
mov edx, OFFSET resultMsg
call WriteString
call WriteDec
call Crlf
call Crlf

; find gcd(0, 0)
push 0
push 0
call Gcd
mov edx, OFFSET resultMsg
call WriteString
call WriteDec
call Crlf
call Crlf

exit
main ENDP 


; function gcd(a, b)
Gcd PROC  
	push ebp			; save base pointer
	mov  ebp, esp		; base of stack frame	
	mov  eax, [ebp+12]	; get a
	mov  ebx, [ebp+8]	; get b
	xor  edx, edx		; used as remainder in div instr.

	.IF eax < ebx		; make sure dividend is greater than divisor
		xchg eax, ebx
	.ENDIF

	; if (b == 0)
	;	return a;		
	.IF ebx == 0		
		jmp return_a
	.ENDIF	
	
	;else
	;	return gcd(b, a mod b);
	returnGcd:
		div ebx			
		mov eax, ebx	; move divisor into a
		mov ebx, edx	; move remainder into b
		; simulate initial procedure call from main PROC with new a and b values
		push eax		
		push ebx
		call Gcd
	
	return_a:		
		pop ebp
		ret 8			; clean up stack
Gcd ENDP
END main   