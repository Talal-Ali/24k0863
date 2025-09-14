INCLUDE Irvine32.inc


.data
    msg byte "Hello World", 0
    temp dword ?
.code   
main PROC
    mov edx, offset msg
    call writestring
main ENDP
END main
