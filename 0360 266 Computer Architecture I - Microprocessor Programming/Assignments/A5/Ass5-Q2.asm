Comment !
Project		: Assignment 5
Author		: Jason Choquette
Student ID	: 104 337 378
Date		: 03/16/18
!

TITLE	Assignment 5		(Ass5-Q2.asm) 
INCLUDE Irvine32.inc
INCLUDE Macros.inc	





.data
factorial DWORD 8
msg BYTE " Factorial is: ", 0
.code



main PROC
mov eax, factorial 
call WriteDec

mov ecx, factorial	; uses a loop to caluclate factorial
mov eax, 1			; stores factorial result
call Fact

mov edx, OFFSET msg
call WriteString
call WriteDec

call Crlf
call Crlf
call WaitMsg
exit
main ENDP 


Fact PROC 	
L1:
mov ebx, ecx
mul ebx	
loop L1
ret
Fact ENDP


END main