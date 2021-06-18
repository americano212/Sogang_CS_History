TITLE TEST code : My first Assembly code

INCLUDE irvine32.inc

.data
INCLUDE hw1.inc

.code
main PROC
	mov edi, OFFSET array1 ; address of array1
	mov ecx, LENGTHOF array1 ; loop count
	DEC ecx ; loop count -1
	mov eax, 0 ; sum=0
	mov ebx, [edi] ; temp
	add edi, TYPE array1 ; add+8

L1:
	mov edx, [edi]
	sub edx, ebx
	add eax, edx
	mov ebx, [edi]
	add edi, TYPE array1
	loop L1

	call DumpRegs
	exit
main ENDP
END main