TITLE TEST code : HW3

INCLUDE irvine32.inc

.data
INCLUDE hw3.inc
temp DWORD ?

.code
main PROC
	mov ecx, Y; ecx = 3
	DEC ecx
	mov ebx, X; ebx = 2
	mov eax, X; eax = 2
L1:
	mul ebx;
	loop L1

	mov temp, eax; temp = X^Y
	mov ecx, X;
	DEC ecx
	mov ebx, Y;
	mov eax, Y;

L2:
	mul ebx;
	loop L2

	mov ebx, eax
	mov eax, temp
	
	call DumpRegs
	exit
main ENDP
END main