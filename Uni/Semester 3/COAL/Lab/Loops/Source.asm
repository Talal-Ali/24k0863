INCLUDE Irvine32.inc

.data


.code
main PROC
   mov eax, 2
   mov ebx, eax
   mov ecx, eax
   shl eax, 4
   shl ebx, 3
   shl ecx, 1
   add eax, ebx
   add eax, ecx

   call writedec
exit
main ENDP
END main
