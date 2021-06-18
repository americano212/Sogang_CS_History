TITLE TEST code : HW2

INCLUDE irvine32.inc

.data
INCLUDE hw2.inc

.code
main PROC
	mov ecx, fib ; loop count
	DEC ecx; loop count -1
	DEC ecx; loop count -1
	mov ebx, 1 ; n-2
	mov edx, 1 ; n-1
	
	
L1:
	mov eax, 0
	add eax, ebx; 
	add eax, edx; n = n-1 + n+2
	mov ebx, edx;
	mov edx, eax;

	loop L1


	call DumpRegs
	exit
main ENDP
END main