INCLUDE Irvine32.inc


.data
d1 dword 1
d2 dword 2



.code
;addi PROTO a:DWORD, b:DWORD

addi PROC
push ebp
mov ebp, esp
mov eax, [ebp+8]
add eax, [ebp+12]
mov ebx, 6
mov [ebp-8], ebx
mov eax, [ebp-8]
call writeint
pop ebp
ret
addi endp


main PROC
push d2
push d1
call addi
pop d1
pop d2

exit
main ENDP
END main
