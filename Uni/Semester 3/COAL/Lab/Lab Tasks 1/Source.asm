INCLUDE Irvine32.inc

.data
bs  BYTE "Blood sugar high",0
sbp BYTE "Systolic Blood pressure high",0
dbp BYTE "Diastolic Blood pressure high",0
p   BYTE "Pulse high",0
bt  BYTE "Body temp high",0
rr  BYTE "Respiration rate high",0
pl  BYTE "Pain Level high",0

msgs DWORD OFFSET bs, OFFSET sbp, OFFSET dbp, OFFSET p, OFFSET bt, OFFSET rr, OFFSET pl

u BYTE "Urgent",0
intermediate BYTE "Intermediate",0
t BYTE "Trivial",0

status BYTE ?
count  BYTE 0

.code
main PROC
    call ReadInt
    mov status, al
    mov esi, OFFSET msgs
    mov count, 0

    test status, 1
    jz next1
    mov edx, [esi + 0*4]
    call WriteString
    call Crlf
    inc count
next1:

    test status, 2
    jz next2
    mov edx, [esi + 1*4]
    call WriteString
    call Crlf
    inc count
next2:

    test status, 4
    jz next3
    mov edx, [esi + 2*4]
    call WriteString
    call Crlf
    inc count
next3:

    test status, 8
    jz next4
    mov edx, [esi + 3*4]
    call WriteString
    call Crlf
    inc count
next4:

    test status, 16
    jz next5
    mov edx, [esi + 4*4]
    call WriteString
    call Crlf
    inc count
next5:

    test status, 32
    jz next6
    mov edx, [esi + 5*4]
    call WriteString
    call Crlf
    inc count
next6:

    test status, 64
    jz after
    mov edx, [esi + 6*4]
    call WriteString
    call Crlf
    inc count
after:

    mov al, count
    cmp al, 5
    jg urgent
    cmp al, 3
    jge intermediate_case
    jmp trivial

urgent:
    mov edx, OFFSET u
    call WriteString
    call Crlf
    jmp done

intermediate_case:
    mov edx, OFFSET intermediate
    call WriteString
    call Crlf
    jmp done

trivial:
    mov edx, OFFSET t
    call WriteString
    call Crlf

done:
    exit
main ENDP
END main
