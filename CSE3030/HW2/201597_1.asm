TITLE TEST code : HW4

INCLUDE irvine32.inc

.data
var1 BYTE "65",0
varsize = ($ - var1)
seven DWORD 1

.code
main PROC
	mov esi,0
	mov esi,OFFSET var1
	mov ecx,varsize
	dec ecx
	add esi,ecx
	dec esi
	mov ebx,0
	
L1:
	mov eax,0
	mov al,[esi]
	sub eax,30h
	mul seven
	add ebx, eax
	mov eax,7
	mul seven
	mov seven,eax
	dec esi
	loop L1
	mov eax,ebx
	call DumpRegs
	exit
main ENDP
END main