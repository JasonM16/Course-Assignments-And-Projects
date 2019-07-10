Comment !
Project		: Assignment 3
Author		: Jason Choquette
Student ID	: 104 337 378
Date		: 03/02/18
!

TITLE	Assignment 3		(Ass3.asm) 
INCLUDE Irvine32.inc

.data
; which command did the user select?
command						DWORD ?			

; the vector data structure
vector						DWORD 50 dup (?)	

; this is used to represent the internal stack frame
internalStack				DWORD 50 dup (?)

; size of the vector.
N							DWORD 0				

; stack empty on program start-up. TRUE = 1
stackIsEmpty				DWORD  1				

; build-up string integer from single byte values
; for the ParseInteger32 command from Irvine library.
numToken					BYTE  0				

; temporary storage for user input
buffer						BYTE  51 dup(0)		

; This is a table with offsets of procedures  
; It is used to execute indirect procedure calls.
CaseTable					DWORD 0
							DWORD Command_0
							DWORD 1
							DWORD Command_1
							DWORD 2
							DWORD Command_2
							DWORD 3
							DWORD Command_3	

; number of entries in the table
NumberOfEntries				EQU	  4			

; CONSTANTS
TRUE						EQU   1
FALSE						EQU   0		

; INPUT STRINGS
getOperation				BYTE "What do you want to do now? >", 0
getN						BYTE "What is the size N of Vector? >", 0
getVectorContents1			BYTE "What are the ", 0
getVectorContents2			BYTE " values in Vector? >", 0


; OUTPUT STRINGS
displayVectorEquals			BYTE "Vector = ", 0
displayVectorIs				BYTE "Vector is ", 0
displayStackIs				BYTE "Stack is ", 0
displayN			        BYTE "Size of Vector N = ", 0
displayInvalidN	            BYTE "Size must be positive.", 0
displayZeroVector			BYTE "Please enter a Vector size greater than zero", 0
dispayStackIsEmpty			BYTE "Stack is empty", 0
dispayStackNotEmpty			BYTE "Stack not empty", 0
displayBefore				BYTE "before ", 0
displayAfter				BYTE "after ", 0
displayArrayToStack			BYTE "ArrayToStack", 0
displayStackToArray			BYTE "StackToArray", 0
displayStackReverse			BYTE "StackReverse", 0
displayExit					BYTE "I am exiting... Thank you Honey... and Get lost...", 0
space						BYTE "  ", 0

; ERROR STRINGS
invalidOption				BYTE "Invalid Option. Please select from the following: ", 0
emptyStack					BYTE "Error - Stack is empty: Cannot perform StackToArray", 0

; MENU STRING
menuString					BYTE "   0. Create a new Vector.", 0dh,0ah
							BYTE "   1. Call ArrayToStack procedure.", 0dh,0ah
							BYTE "   2. Call StackToArray procedure.", 0dh,0ah
							BYTE "   3. Call StackReverse procedure.", 0dh,0ah
							BYTE "  -1. Exit program.", 0
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;  END .data  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

.code
;-----------------------------------------------
main PROC

	Menu: 	
		mov  edx, OFFSET getOperation
		call WriteString		
		call ReadInt
		call Crlf
		mov  command, eax
		mov  ebx, OFFSET CaseTable
		mov  ecx, NumberOfEntries

	L1:
		.IF command == -1 
			jmp toExit
		.ELSEIF (command < 0 ) || (command > 4)  
			jmp invalidOperation	
		.ENDIF				
		mov  eax, command
		cmp  eax, [ebx]		
		jne  L2
		call NEAR PTR [ebx+4] ; calls the selected command	
		; continue until user enters -1
		jmp  Menu	

	L2:		
		add  ebx, 8
		loop L1			

	invalidOperation:
		call Crlf
		call Crlf
		mov  edx, OFFSET invalidOption
		call WriteString
		call Crlf
		call Crlf				
		mov  edx, OFFSET menuString
		call WriteString
		call Crlf			
		call Crlf
		jmp  Menu		
		
	toExit:
		mov edx, OFFSET displayExit
		call WriteString
		call Crlf	
	exit


main ENDP


; COMMAND PROCEDURES


;-----------------------------------------------
Command_0 PROC
	
	call GetNFromUser			
	cmp  N, 0
	je   main
	call GetVectorContents		
	mov  edx, OFFSET displayN
	call WriteString
	call ShowN
	mov  edx, OFFSET displayVectorEquals
	call WriteString		
	call ShowVectorContents
	call Crlf
	call ShowStackState	
	ret
Command_0 ENDP
	






;-----------------------------------------------
Command_1 PROC	

	mov  edx, OFFSET displayVectorIs
	call WriteString
	call ShowVectorContents
	mov  edx, OFFSET displayBefore
	call WriteString
	mov  edx, OFFSET displayArrayToStack
	call WriteString
	call Crlf
	mov  edx, OFFSET displayStackIs
	call WriteString	
	call ArrayToStack
	call ShowStackContents
	mov  edx, OFFSET displayAfter
	call WriteString
	mov  edx, OFFSET displayArrayToStack
	call WriteString
	call Crlf
	call ShowStackState
	ret
Command_1 ENDP



;-----------------------------------------------
ArrayToStack PROC  ; command1

	mov esi, OFFSET vector	
	mov ecx, N			
	
	pushToStack:
		mov  ebx, [esi]
		push ebx		
		add  esi, TYPE vector
	loop pushToStack
		
	mov stackIsEmpty, FALSE			; set stack is empty to false
	mov ecx, N		
	mov esi, OFFSET internalStack	

	popFromStack:
	pop ebx
	mov [esi], ebx								
	add esi, TYPE internalStack
	loop popFromStack

	ret 
ArrayToStack ENDP




;-----------------------------------------------
Command_2 PROC		
	
	call StackToArray
	mov  edx, OFFSET displayStackIs
	call WriteString
	call ShowStackContents
	mov  edx, OFFSET displayBefore
	call WriteString
	mov  edx, OFFSET displayStackToArray
	call WriteString
	call Crlf

	mov  edx, OFFSET displayVectorIs
	call WriteString
	call ShowVectorContents
	mov  edx, OFFSET displayAfter
	call WriteString
	mov  edx, OFFSET displayStackToArray
	call WriteString
	call Crlf
	call ShowStackState

	ret
Command_2 ENDP
		


StackToArray PROC ; command2

	.IF stackIsEmpty == TRUE						
		mov edx, OFFSET emptyStack
		call WriteString
		call Crlf
		call Crlf	
		jmp main
	.ENDIF
	
	mov esi, OFFSET internalStack	
	mov ecx, N			
	
	pushToStack:
		mov  ebx, [esi]
		push ebx		
		add  esi, TYPE vector
	loop pushToStack
		
	mov stackIsEmpty, TRUE			
	mov ecx, N		
	mov esi, OFFSET vector	

	popFromStack:
		pop ebx
		mov [esi], ebx								
		add esi, TYPE vector
	loop popFromStack	

	ret
StackToArray ENDP


;-----------------------------------------------
Command_3 PROC

	mov stackIsEmpty, FALSE
	mov  edx, OFFSET displayVectorIs
	call WriteString
	call ShowVectorContents
	mov  edx, OFFSET displayBefore
	call WriteString
	mov  edx, OFFSET displayStackReverse
	call WriteString
	call Crlf
	call ShowStackState
	
	call StackReverse
	mov  edx, OFFSET displayVectorIs
	call WriteString
	call ShowVectorContents
	mov  edx, OFFSET displayAfter
	call WriteString
	mov  edx, OFFSET displayStackReverse
	call WriteString
	call Crlf
	call ShowStackState
	
	ret
Command_3 ENDP




;-----------------------------------------------
StackReverse PROC ;command3 

	mov esi, OFFSET vector	
	mov ecx, N			
	
	pushToStack:
		mov  ebx, [esi]
		push ebx		
		add  esi, TYPE vector
	loop pushToStack
		
	mov stackIsEmpty, FALSE			; set stack is empty to false
	mov ecx, N		
	mov esi, OFFSET vector	

	popFromStack:
		pop ebx
		mov [esi], ebx								
		add esi, TYPE vector
	loop popFromStack

	mov stackIsEmpty, TRUE

	ret
StackReverse ENDP




; UTILITY PROCEDURES


;-----------------------------------------------
GetNFromUser PROC 
;
; 
; 
; Receives: nothing. 
; Returns: nothing
;-----------------------------------------------
	call Crlf
	mov  edx, OFFSET getN
	call WriteString
	call ReadInt
	mov  N, eax
	cmp  eax, 0
	je   zeroVector			
	jl   NError
	call MultiplyDWORD	
	ret

	zeroVector:	
		mov  edx, OFFSET displayZeroVector
		call WriteString
		call Crlf				
		jmp  GetNFromUser
	
	NError:
		mov  edx, OFFSET displayInvalidN
		call WriteString
		call Crlf			
		jmp  GetNFromUser
	ret
GetNFromUser ENDP
	


;-----------------------------------------------
MultiplyDWORD PROC
;
; 
; 
; Receives: nothing. 
; Returns: nothing
;-----------------------------------------------
mov ebx, 0
mov ecx, 4

	L1:
	add ebx, N
	loop L1
ret
MultiplyDWORD ENDP



;-----------------------------------------------
GetVectorContents PROC 
;
; 
; 
; Receives: nothing. 
; Returns: nothing
;-----------------------------------------------
	; display message "What are the # values in Vector? "
	mov  edx, OFFSET getVectorContents1
	call WriteString
	mov  eax, N
	call WriteDec
	mov  edx, OFFSET getVectorContents2
	call WriteString
		
		
	mov  edx, OFFSET buffer			
	mov  esi, OFFSET buffer ; pointer to the buffer	
	mov  ecx, SIZEOF buffer + 1
	; read in the values as a string to be parsed
	call ReadString	; string of numbers is now in buffer


	mov  edx, 0
	mov  ebx, 0
	; should only be called if first BYTE of string or a space character
	; has been encountered elsewhere
	continue:
		call GetNextBYTE
		call IsDigit
		jz   stateC
		cmp  al, 10		; null-termination
		je   endOfInput
		cmp  al, 32		; ascii space
		jmp  continue		
		
	stateB:
		call GetNextBYTE
		call IsDigit
		jz   stateC
		jnz  convertToInt
		jmp  continue
		
	stateC:
		; store the digit in temp variable to
		; be parsed in convert_to_int label
		mov  numToken[edx], al			
		inc  edx
		jmp  stateB		; could still have more digits to add to temp
			

	convertToInt:			
		mov  numToken[edx], 58
		mov  edx, OFFSET numToken
		call ParseInteger32			
			
		mov  vector[ebx], eax
		add  ebx, TYPE vector
			
		mov  edx, 0	
		cmp  eax, 0			
		jmp  continue

	endOfInput:				
		call Crlf			
	ret
GetVectorContents ENDP



;-----------------------------------------------
GetNextBYTE PROC 
;
; 
; 
; Receives: nothing. 
; Returns: nothing
;-----------------------------------------------
	mov al, [esi]
	inc esi
	ret
GetNextBYTE ENDP



;-----------------------------------------------
ShowStackState PROC 
				
	cmp  stackIsEmpty, TRUE
	je   stackEmpty		
	jmp  stackNotEmpty			

	stackEmpty:				
		mov  edx, OFFSET dispayStackIsEmpty	
		call WriteString
		call Crlf	
		call Crlf
		ret

	stackNotEmpty:				
		mov  edx, OFFSET dispayStackNotEmpty
		call WriteString
		call Crlf	
		call Crlf
		ret			
			
ShowStackState ENDP
		

					


;-----------------------------------------------
ShowStackContents PROC 
;
; 
; 
; Receives: nothing. 
; Returns: nothing
;-----------------------------------------------
	mov edx, OFFSET space		
	mov esi, OFFSET internalStack
	mov ecx, N
	show_digit:			
		mov  eax, [esi]
		call WriteDec		
		call WriteString
		add esi, TYPE internalStack
	loop show_digit			

	ret
ShowStackContents ENDP		



;-----------------------------------------------
ShowVectorContents PROC 

	mov ecx, N
	mov edx, OFFSET space		
	mov ebx, OFFSET vector

	show_digit:			
		mov  eax, [ebx]
		call WriteDec		
		call WriteString
		add  ebx, TYPE vector
	loop show_digit					
	ret
ShowVectorContents ENDP		




;-----------------------------------------------
ShowN PROC 
;
; 
; 
; Receives: nothing. 
; Returns: nothing
;-----------------------------------------------
	mov  eax, N
	call WriteDec
	call Crlf
	ret
ShowN ENDP
	
	

;-----------------------------------------------
ClearVector PROC 

	; have to clear everything!!
	mov ecx, SIZEOF vector
	mov edi, OFFSET vector
	mov esi, 7FFFFFFFh
	free:
		mov [edi], esi
		inc edi
	loop free
	ret
ClearVector ENDP




END main  