INCLUDE Irvine32.inc

.code



.data
main Proc
mov ax, -128
shl eax, 16
call writeint
call crlf
sar eax, 16
call writeiny
call crlf

main ENDP
END main