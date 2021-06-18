
INCLUDE Irvine32.inc
.data
buffer BYTE 42 DUP(0)
byteCount DWORD ?

init_ BYTE "Type_A_String_To_Reverse: ",0
end_ BYTE "Reversed String: ",0
bb_ BYTE "Bye!",0

.code
main PROC
L3:
	mov edx, OFFSET init_
	call WriteString


	mov edx, OFFSET buffer
	mov ecx, SIZEOF buffer
	call ReadString
	mov byteCount, eax

	cmp byteCount,41
	jz L3

	cmp byteCount,0
	jz finish

	mov edx, OFFSET end_
	call WriteString

	mov ecx,byteCount
	mov esi,0
	
L1:
	movzx eax, buffer[esi]
	push eax
	inc esi
	loop L1

	mov ecx,byteCount
	mov esi,0

L2:
	pop eax
	mov buffer[esi],al
	inc esi
	loop L2

	mov edx,OFFSET buffer
	call WriteString
	call Crlf
	
	loop L3
finish:
	mov edx, OFFSET bb_
	call WriteString

	exit
main ENDP
END main