
INCLUDE Irvine32.inc
.data
intVal SDWORD ?
init_ BYTE "Input : ",0

.code
main PROC
	mov edx, OFFSET init_
	call WriteString
	call ReadInt
	mov intVal,eax;
	mov ebx, 1
L1:
	mov edx, ebx
	mov ecx, edx
L2:
	mov al,'*'
	call WriteChar
	loop L2
	cmp ebx, intVal 
	jz finish
	call Crlf
	inc ebx
	loop L1

finish:
	exit
main ENDP
END main