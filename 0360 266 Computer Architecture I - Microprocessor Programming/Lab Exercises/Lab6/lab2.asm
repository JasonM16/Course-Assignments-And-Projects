TITLE  LAB 2                  (lab2.asm)
Comment !
Description: This program illustrates addition and subtraction of 16-bit and 32-bitintegers and uses a call DumpRegs statement to display the register values.
WARNING: This program contains errors. 
!

TITLE	     Program Lab2		(lab2sol.asm) 
INCLUDE Irvine32.inc

.data
val1 dword 4040h 
val2 dword 1555h
val3 byte "Hello World", 0

.code
main PROC
	mov EDX, offset val3
	call WriteString
	call crlf

	mov eax, val1
	add eax, val2 
	mov ecx, val2
	sub ecx, 500h
	mov ebx, 3000h
	add eax, ebx	
	sub ax,cx
	add val2, ecx

	mov eax, 1111h
	add val1, eax

	call DumpRegs

	exit
main ENDP
END main  
