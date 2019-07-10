TITLE  LAB 2                  (lab3.asm)
Comment !

OBJECTIVES: 
i) To learn how to write a simple program in assembly language. 
ii) To become familiar with different data types.
iii) To learn to declare and initialize simple arrays.

Problem: 
i) Create and initialize an array of at least 5 unsigned word integers (myArray) 
	•	Find the size of the array in number of bytes and store this value in a variable 
		(myArraySize). NOTE: You must properly declare the variable first.
	•	Find the number of elements in the array and store this value in register ecx.

ii) Define a byte type variable (myByte1) and initialize it to a lowercase letter.  
	Convert it to the corresponding uppercase letter and store the result in another variable (myByte2). 

iii) Use DUP operator to create an array of 10 signed doubleword integers (myArray2) initialized to -76. 

iv) Change the value of the 2nd element of the array to 11112222h. Store the upper 2 bytes of the second 
	array element (new value) in register bx.

Hints:
 1. Define the different arrays and variables in the data segement. 
 2: Use SIZEOF to find array size in bytes and LENGTHOF to find number of array elements.
 3: Begin code segment
 4: Move myByte1 to register al. Use ASCII table from book to covert to uppercase.
 5: Store contents of al in myByte2.
 6: Update and store the second element of myArray2 
 7.  Use PTR operator to store upper two bytes into register bx.
 
!

TITLE	     Program Lab3		(lab3sol.asm) 
INCLUDE Irvine32.inc

.data
myArray word 5 dup (0)			; Create and initialize an array of at least 5 unsigned word integers (myArray)
myArraySize word ?
myByte1 byte 'j'				; Define a byte type variable (myByte1) and initialize it to a lowercase letter.
myByte2 byte 0						
myArray2 sdword 10 Dup (-76)	; Use DUP operator to create an array of 10 signed doubleword integers (myArray2) initialized to -76. 


.code
main PROC

	mov esi, offset myArray2	; for indexing into array
	mov ax, lengthof myArray	; Find the size of the array in number of bytes and store this value in a variable (myArraySize).
	mov myArraySize, ax
	mov ecx, SIZEOF myArray		; Find the number of elements in the array and store this value in register ecx.

	mov al, myByte1				; Convert it to the corresponding uppercase letter and store the result in another variable (myByte2). 
	sub al, 20h
	mov myByte2, al

	mov ebx, 11112222h			; Change the value of the 2nd element of the array to 11112222h. 
	mov [esi + 4], ebx			; myArray is type dword (4-bytes) each offset is 4 bytes. 
	mov bx, 0					; Store the upper 2 bytes of the second array element (new value) in register bx.


	call DumpRegs

	exit
main ENDP
END main  
