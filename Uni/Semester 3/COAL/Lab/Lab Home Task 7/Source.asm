INCLUDE Irvine32.inc

.data
	str BYTE 32 DUP(?)
	msg1 BYTE "Password is strong", 0
	msg2 BYTE "Password must include at least 1 digit", 0

.code
main PROC
	
	mov edx, offset str
	mov ecx, 31
	call readstring
	
exit
main ENDP
END main
