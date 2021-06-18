TITLE TEST code : Sort

INCLUDE irvine32.inc

.data
INCLUDE hw3.inc

init_ BYTE "Before sort : ", 0
end_ BYTE "After sort : ", 0
bb_ BYTE "Bye!",0


tmp DWORD 1 DUP(0)

.code
main PROC
	mov edx, 0
	mov edx, OFFSET init_
	call WriteString
	mov ecx, LenData
	mov esi, 0
	mov ebx,0
L1:
	mov eax, 0
	mov eax, ArrData[esi]
	
	call WriteHex
	mov al,','
	inc ebx
	add esi,4
	cmp ebx, LenData
	jae next1
	call WriteChar
	Loop L1
next1:
	mov edi, 0
	iLOOP:
		mov ecx, LenData
		sub ecx, tmp
		dec ecx
		
			cmp ecx,0
			JE endSort
		mov esi,edi
		jLOOP:
			add esi, TYPE ArrData
			mov edx, ArrData[edi]
			cmp ArrData[esi],edx
			JAE noChange
			;Change:
				mov eax, ArrData[esi]
				mov edx, ArrData[edi]
				mov ArrData[edi],eax
				mov ArrData[esi],edx
			noChange:
				loop jLoop

				add edi, TYPE ArrData
				inc tmp
		jmp iLoop
	endSort:
	call Crlf
	mov edx, 0
	mov edx, OFFSET end_
	call WriteString

	mov ecx, LenData
	mov esi, 0
	mov ebx,0
L2:
	mov eax, 0
	mov eax, ArrData[esi]
	
	call WriteHex
	mov al,','
	inc ebx
	add esi,4
	cmp ebx, LenData
	jae next2
	call WriteChar
	Loop L2
next2:
	call Crlf
	mov edx, 0
	mov edx, OFFSET bb_
	call WriteString
	exit

main ENDP
END main