Comment !
Project		: Assignment 2
Author		: Jason Choquette
Student ID	: 104 337 378
Date		: 02/16/18
!

TITLE	Assignment 2		(Ass2-Q1.asm) 
INCLUDE Irvine32.inc

.data
Vector						sdword 50 dup (?)	
buffer						byte   51 dup(0)	; extra null character
vectorSize					dword  0			; test for negative value
sumOfNegatives				dword  0 
evenNumbersCount			dword  0
valueI						dword  0
valueJ						dword  0
currentVectoreIndex			dword  0
tempNumAsString				byte   8
tempNumAsString2			byte   8
bZero						byte  "0", 0
min							sdword 0
hi							sdword ?
lo							sdword ?
; INPUT
getVectorSize				byte "What is the size N of Vector? >", 0
getVectorContents1			byte "What are the ", 0
getVectorContents2			byte " values in Vector? >", 0
getValuesIAndJ				byte "Please give me two values I and J such that 1 <= I <= J <= N >", 0
displayRepeatMessage		byte "Repeat with a new Vector of different sizer and/or content? >", 0
workWithMe					byte "Repeat with a new Vector of different sizer and/or content? >", 0

; OUTPUT
displayVectorEquals			byte "Vector = ", 0
displayVectorSize			byte "Size of Vector N = ", 0
displayInvalidVectorSize	byte "Size must be positive or zero.", 0
displaySumOfNegatives		byte "The sum of all the negative values in Vector is: Sum = ", 0
displayNumberOfPositives	byte "The number of all positive values in Vector is: Count = ", 0
displayI					byte "I = ", 0
displayJ					byte " and J = ", 0
displayAnd					byte ", and", 0
displayInvalidIandJResults	byte "Invalid I or J", 0
displayIsPalindromeResult	byte "Vector is a palindrome because it reads the same way in both directions.", 0
displayNotPalindromeResult	byte "Vector is not a palindrome.", 0
minPositionBetweenI			byte "The minimum value between position ", 0
minPostitionBetweenJ		byte " and position ",0
ofVector					byte " is: Minimum = ",0
minValue					byte "The minimum value is 0",0 
invalidOption				byte " Invalid Option. Press 'y' or'Y to continue. Press 'n' or 'N' to quit.", 0

.code
main PROC


	getVectorSizeLoop:
	call Crlf
	call Crlf
		mov edx, offset getVectorSize
		call WriteString
		call ReadInt
		mov vectorSize, eax
		cmp vectorSize, 0
		je zeroVector
		cmp eax, 0
		je zeroVector
		jg getVectorContents_
		jmp vectorSizeError

	zeroVector:				
		call Crlf
		mov edx, offset displayIsPalindromeResult
		Call WriteString
		call Crlf
		call Crlf
		mov edx, offset displaySumOfNegatives
		call WriteString		
		mov edx, offset bZero
		call WriteString
		call Crlf
		call Crlf
		mov edx, offset displayNumberOfPositives
		call WriteString				
		mov edx, offset bZero
		call WriteString
		call Crlf
		call Crlf
		mov edx, offset minValue
		call WriteString
		call Crlf
		call Crlf
		jmp newVector
	
	vectorSizeError:
		mov edx, offset displayInvalidVectorSize
		call WriteString
		call Crlf
		mov eax, 0
		jmp getVectorSizeLoop


	getVectorContents_:
		; display message "What are the # values in Vector? "
		mov edx, offset getVectorContents1
		call WriteString
		mov eax, vectorSize
		call WriteDec
		mov edx, offset getVectorContents2
		call WriteString
		
		
		mov edx, offset buffer			
		mov esi, offset buffer ; pointer to the buffer	
		mov ecx, sizeof buffer + 1
		; read in the values as a string to be parsed
		call ReadString	; string of numbers is now in buffer


		mov edx, 0
		; should only be called if first byte of string or a space character
		; has been encountered elsewhere
		continue:
			call getNextByte
			call IsDigit ; no sign
			jz StateC
			cmp al, 43
			je addPlusSign
			cmp al, 45
			je addMinusSign			
			cmp al, 10		; null-termination
			je displayStuff
			cmp al, 32		; ascii space
			jmp continue	
			

		getNextByte:
			mov al, [esi]
			inc esi
			ret

		StateA:			
			call getNextByte	; loop until a space is encountered. 
			call IsDigit		
			jz   StateA			; if digit, continue looping. Eat up the number.
			jnz  continue		; if not a digit must be a space. continue


		isPositiveNumber:
			add evenNumbersCount, 1
			jmp continue


		addPlusSign:
			mov tempNumAsString[edx], al
			inc edx
			jmp StateB

		addMinusSign:
			mov tempNumAsString[edx], al
			inc edx
			jmp StateB

		
		StateB:
			call getNextByte
			call IsDigit
			jz   StateC
			jnz  convertToInt
			jmp  continue
		
		StateC:
			mov tempNumAsString[edx], al	; store the digit in temp variable to
			; be parsed in convert_to_int label
			inc edx
			jmp StateB			; could still have more digits to add to temp
			

		convertToInt:
			mov tempNumAsString[edx], 58
			mov edx, offset tempNumAsString
			call ParseInteger32			
			
			; store in vector
			mov ebx, currentVectoreIndex
			mov Vector[ebx], eax
			add ebx, 4
			mov currentVectoreIndex, ebx
			mov edx, 0	
			cmp eax, 0
			jg isPositiveNumber
			add sumOfNegatives, eax	
			jmp continue

	
	displayStuff:
		; display message "Size of Vector N = "
		mov edx, offset displayVectorSize
		call WriteString
		mov eax, vectorSize
		call WriteDec
		call Crlf
		call Crlf

		; display the contents of the buffer (Vector)
		mov edx, offset displayVectorEquals
		call WriteString
		mov edx, offset buffer
		call WriteString
		call Crlf
		call Crlf
		

		mov edx, offset displaySumOfNegatives
		Call WriteString
		
		mov eax, sumOfNegatives
		call WriteInt
		call Crlf
		mov edx, offset displayNumberOfPositives
		call WriteString
		mov eax, evenNumbersCount
		call WriteDec
		call Crlf


		; BEGIN I and J values ------------------------------------------------
		getIandJ:
			call Crlf
			call Crlf
			mov edx, offset getValuesIAndJ
			call WriteString
		

		; 1 <= I <= J <= N ... n = vectorSize
		mov edx, offset buffer
		
		mov eax, 0
		mov ebx, 0
		
		call ReadString
		call Crlf		

		mov esi, offset buffer
		mov ecx, sizeof buffer+1
		mov al, [esi]
		call ParseInteger32		
		mov valueI, eax	
		xor eax, eax		
		inc esi
		spa:
			call getNextByte
			call IsDigit
			cmp al, 0		; null-termination
			jz goo
			jnz addToBuff			
			cmp al, 20			
			jnz spa		
			
			
		addTobuff:
			mov tempNumAsString2[ebx], al	; store the digit in temp variable to
			inc ebx			
			jmp spa

		goo:
			mov tempNumAsString2[ebx], 58
			mov edx, offset tempNumAsString2
			call ParseInteger32					
			mov valueJ, eax



		mov eax, valueI		; EAX = I
		cmp eax, 1			; Compare I to 1 
		jb displayError		; jb: jump if I below 1 
		cmp eax, valueJ		; Compare I to J
		ja displayError		; ja: jump if J above I


		mov eax, valueJ		; EAX = J
		cmp eax, 1			; Compare J to 1 
		jb  displayError	; jb: jump if J below 1
				
		
		mov eax, vectorSize	; EAX = Size of Vector
		cmp eax, valueJ		; Compare Size of Vector to J
		jb displayError		; jb: jump if Size of Vector below J
		cmp eax, valueI		; Compare Size of Vector to I
		jb displayError		; jb: jump if Size of Vector below I
		jmp showIandJ
		
		displayError:
			mov edx, offset displayInvalidIandJResults
			call WriteString
			call Crlf
			jmp getIandJ
		

		showIandJ:
		mov edx, offset displayI
		call WriteString
		mov eax, valueI
		call WriteDec
		mov edx, offset displayJ
		call WriteString
		mov eax, valueJ
		call WriteDec
		mov edx, offset displayAnd
		call WriteString
		call Crlf


		mov edx, offset minPositionBetweenI
		call WriteString
		mov eax, valueI
		call WriteDec
		mov edx, offset minPostitionBetweenJ
		call WriteString
		mov eax, valueJ
		call WriteDec
		mov edx, offset ofVector
		call WriteString

		; END I and J values ------------------------------------------------


		; BEGIN find minimum
		findMinimum:

		;-----------------------------------------
		;mov eax, 0
		;mov ebx, 0
		;mov ecx, 0
		;mov esi, 0
		
		mov esi, valueI
		dec esi
		mov eax, esi
		mov ebx, 4
		mul ebx
		mov esi, eax
		mov eax, valueJ
		
		
		mov eax, valueI
		sub valueJ, eax
		mov ecx, valueJ						;initialize loop counter
		;dec ecx								; zero indexed

		
		mov edi, sdword ptr [Vector+esi]	;EDI = starting address of Vector based on I 
		mov eax, edi
		mov min, eax						; set intial min value as first element to check
		
		mini:				
			cmp ecx, 0
			je stuff
			add esi, 4			
			mov edi, sdword ptr [Vector+esi]	;EDI = address of Vector
			mov eax, edi
			cmp min, eax
			jg condition1				
		loop mini

			jmp stuff

			condition1:				
				mov min, eax		
				dec ecx
				jmp mini

		stuff:
		; ----------------------------------------			
			mov eax, min
			call WriteInt
			call Crlf
			jmp beginPalindrome

			

			

		; END find minimum
		
		;---------Good below -------------
		beginPalindrome:

		; BEGIN Palindrome check

		mov ecx, vectorSize		
		dec vectorSize
		mov eax, vectorSize
		mov ebx, 4
		mul ebx		
		mov hi, eax
		mov edx, hi

		mov lo, 0
		mov eax, lo
		mov esi, sdword ptr [Vector+eax]		;EDI = starting address of Vector based on I 
		mov edi, sdword ptr [Vector+edx]	;EDI = starting address of Vector based on I 

		
		pal:
			mov eax, esi
			mov ebx, edi
			cmp eax, ebx
			jnz displayNotPal
			add lo, 4
			mov eax, lo
			sub hi, 4
			mov edx, hi
			
			mov esi, sdword ptr [Vector+eax]	;EDI = starting address of Vector based on I 
			mov edi, sdword ptr [Vector+edx]	;EDI = starting address of Vector based on I 
			
		loop pal


		displayPal:
			call Crlf
			mov edx, offset displayIsPalindromeResult
			call WriteString
			call Crlf
			call Crlf
			call Crlf
			jmp newVector

		displayNotPal:
			call Crlf
			mov edx, offset displayNotPalindromeResult
			call WriteString
			call Crlf
			call Crlf
			call Crlf
			jmp newVector						


		newVector:			
			mov sumOfNegatives, 0 
			mov evenNumbersCount,  0
			mov min, 7FFFFFFFh
			
			; have to clear everything!!
			mov ecx, sizeof Vector
				mov edi, offset Vector
				mov esi, 7FFFFFFFh
				free:
					mov [edi], esi
					inc edi
				loop free

			mov edx, offset displayRepeatMessage
			call WriteString
			call ReadChar
			cmp al, 'Y'
			je getVectorSizeLoop
			cmp al, 'y'
			je getVectorSizeLoop
			cmp al, 'N'
			je jumpToExit
			cmp al, 'n'
			je jumpToExit
			mov edx, offset invalidOption
			call WriteString
			call Crlf
			


			
				
				
			;jmp newVector

		;call WaitMsg
	jumpToExit:
	exit
main ENDP
END main  
