TITLE TEST code : HW4

INCLUDE irvine32.inc

.data
INCLUDE hw4.inc

.code
main PROC
	mov edx, OFFSET source
	mov ecx, SIZEOF source

	mov esi, 0

L1:
	mov al, source[esi]
	cmp source[esi],0
	je NEXT
	push ax
	inc esi
	loop L1

NEXT:
	mov ecx, esi
	mov esi,0

L2:
	pop ax
	mov target[esi],al
	inc esi
	loop L2
	mov target[esi],0
	mov edx, OFFSET target
	call WriteString
	exit
main ENDP
END main