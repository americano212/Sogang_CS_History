
INCLUDE Irvine32.inc
.data
buffer BYTE 21 DUP(0)
cpy_buffer BYTE 21 DUP(0)
byteCount DWORD ?

init_ BYTE "Is this string palindrome?: ",0
yes_ BYTE "It's a palindrome!",0
no_ BYTE "It's NOT a palindrome",0

.code
main PROC
	mov edx, OFFSET init_
	call WriteString

	mov edx, OFFSET buffer
	mov ecx, SIZEOF buffer
	call ReadString
	mov byteCount, eax

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
	mov cpy_buffer[esi],al
	inc esi
	loop L2
	INVOKE Str_compare,
        ADDR buffer,
        ADDR cpy_buffer
	je equal
	mov edx, OFFSET no_
	call WriteString
	exit
equal:
	mov edx, OFFSET yes_
	call WriteString
	exit
main ENDP
END main