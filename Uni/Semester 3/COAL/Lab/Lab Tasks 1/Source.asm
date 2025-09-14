INCLUDE irvine32.inc

.data
    baseSalary EQU 150000
    daySalary  EQU (baseSalary / 30)
    overtimePay EQU 4400

    leaves DWORD 3
    overtime DWORD 2
    netSalary DWORD ?
    msg BYTE "NET SALARY IS: ", 0

.code
main PROC

    mov eax, leaves
    imul eax, daySalary      
    mov ebx, baseSalary
    sub ebx, eax             

    mov eax, overtime
    imul eax, overtimePay    
    add ebx, eax             

    mov netSalary, ebx
 
    mov eax, netSalary
    mov edx, offset msg
    call writestring
    call WriteInt
    call Crlf

    exit
main ENDP
END main
