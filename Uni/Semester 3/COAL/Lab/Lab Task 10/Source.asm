INCLUDE Irvine32.inc

.data
    prompt   BYTE "Enter a string: ",0
    inputStr BYTE 80 DUP(?)
    wordCnt  DWORD ?
    
.code
main PROC

    mov edx, OFFSET prompt
    call WriteString

    mov edx, OFFSET inputStr
    mov ecx, 79
    call ReadString

    mov esi, OFFSET inputStr
    mov eax, 0
    mov bl, ' '
    mov dl, 1

countLoop:
    lodsb
    cmp al, 0
    je doneCount

    cmp al, ' '
    je isSpace

    cmp dl, 1
    jne notNewWord
    inc eax

notNewWord:
    mov dl, 0
    jmp countLoop

isSpace:
    mov dl, 1
    jmp countLoop

doneCount:
    mov wordCnt, eax
    mov eax, wordCnt
    call WriteDec

    exit
main ENDP

END main
