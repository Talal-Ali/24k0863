include irvine32.inc

.data
    binString  BYTE 65 DUP(0)
    octString  BYTE 23 DUP(0)
    hexString  BYTE 17 DUP(0)
    promptBin  BYTE "Enter binary: ",0
    promptOct  BYTE "Enter octal: ",0
    promptHex  BYTE "Enter hex: ",0
    pressKey   BYTE "Press any key to exit...",0

.code

clearBuffer PROC
    push eax
    push ecx
    push edi
    mov edi, OFFSET binString
    mov ecx, LENGTHOF binString
    mov al, 0
    rep stosb
    mov edi, OFFSET octString
    mov ecx, LENGTHOF octString
    rep stosb
    mov edi, OFFSET hexString
    mov ecx, LENGTHOF hexString
    rep stosb
    pop edi
    pop ecx
    pop eax
    ret
clearBuffer ENDP

binInput PROC
    push edx
    push ecx
    mov edx, OFFSET binString
    mov ecx, SIZEOF binString
    call ReadString
    pop ecx
    pop edx
    ret
binInput ENDP

octInput PROC
    push edx
    push ecx
    mov edx, OFFSET octString
    mov ecx, SIZEOF octString
    call ReadString
    pop ecx
    pop edx
    ret
octInput ENDP

hexInput PROC
    push edx
    push ecx
    mov edx, OFFSET hexString
    mov ecx, SIZEOF hexString
    call ReadString
    pop ecx
    pop edx
    ret
hexInput ENDP

BinToDec PROC
    push ebx
    push esi
    mov eax, 0
    mov esi, OFFSET binString
b1:
    mov bl, [esi]
    cmp bl, 0
    je bend
    cmp bl, ' '
    je bskip
    cmp bl, 13
    je bskip
    cmp bl, 10
    je bskip
    cmp bl, '0'
    jb bin_invalid
    cmp bl, '1'
    ja bin_invalid
    shl eax, 1
    sub bl, '0'
    add al, bl
bskip:
    inc esi
    jmp b1
bin_invalid:
bend:
    pop esi
    pop ebx
    ret
BinToDec ENDP

OctToDec PROC
    push ebx
    push esi
    mov eax, 0
    mov esi, OFFSET octString
o1:
    mov bl, [esi]
    cmp bl, 0
    je oend
    cmp bl, ' '
    je oskip
    cmp bl, 13
    je oskip
    cmp bl, 10
    je oskip
    cmp bl, '0'
    jb oinvalid
    cmp bl, '7'
    ja oinvalid
    sub bl, '0'
    shl eax, 3
    add al, bl
oskip:
    inc esi
    jmp o1
oinvalid:
    jmp oend
oend:
    pop esi
    pop ebx
    ret
OctToDec ENDP

HexToDec PROC
    push ebx
    push esi
    mov eax, 0
    mov esi, OFFSET hexString
h1:
    mov bl, [esi]
    cmp bl, 0
    je hend
    cmp bl, ' '
    je hskip
    cmp bl, 13
    je hskip
    cmp bl, 10
    je hskip
    cmp bl, '0'
    jb hinvalid
    cmp bl, '9'
    jbe h0_9
    cmp bl, 'A'
    jb hchecklow
    cmp bl, 'F'
    jbe hA_F
hchecklow:
    cmp bl, 'a'
    jb hinvalid
    cmp bl, 'f'
    jbe ha_ff
    jmp hinvalid
h0_9:
    sub bl, '0'
    jmp hproc
hA_F:
    sub bl, 'A'
    add bl, 10
    jmp hproc
ha_ff:
    sub bl, 'a'
    add bl, 10
hproc:
    shl eax, 4
    add al, bl
hskip:
    inc esi
    jmp h1
hinvalid:
    jmp hend
hend:
    pop esi
    pop ebx
    ret
HexToDec ENDP
DecToBin PROC
    LOCAL localBin[33]:BYTE

    mov eax, inp
    mov ecx, 32
    lea edi, localBin
    add edi, 31

genbits:
    shr eax, 1
    jc write1
    mov byte ptr [edi], '0'
    jmp nextBit

write1:
    mov byte ptr [edi], '1'

nextBit:
    dec edi
    loop genbits

    lea eax, localBin
    add eax, 32
    mov byte ptr [eax], 0

    lea edx, localBin
    call WriteString
    call CrLf
    ret
DecToBin ENDP

DecToHex PROC
    LOCAL localHex[9]:BYTE
    mov eax, inp
    mov ecx, 8
    lea edi, localHex
    add edi, 7

hexloop:
    mov edx, eax
    and edx, 0Fh

    cmp edx, 9
    jle hexdigit
    add edx, 7
hexdigit:
    add edx, '0'
    mov [edi], dl

    shr eax, 4
    dec edi
    loop hexloop

    lea eax, localHex
    add eax, 8
    mov byte ptr [eax], 0

    lea edx, localHex
    call WriteString
    call CrLf
    ret
DecToHex ENDP

DecToOct PROC
    LOCAL localOct[12]:BYTE

    mov eax, inp
    mov ecx, 11
    lea edi, localOct
    add edi, 10

octloop:
    mov edx, eax
    and edx, 7
    add edx, '0'
    mov [edi], dl

    shr eax, 3
    dec edi
    loop octloop

    lea eax, localOct
    add eax, 11
    mov byte ptr [eax], 0

    lea edx, localOct
    call WriteString
    call CrLf
    ret
DecToOct ENDP

main PROC
    call clearBuffer

    mov edx, OFFSET promptOct
    call WriteString
    call octInput
    call OctToDec
    call WriteDec
    call CrLf

    call clearBuffer
    
    mov edx, OFFSET promptBin
    call WriteString
    call binInput
    call BinToDec
    call WriteDec
    call CrLf

    call clearBuffer
    
    mov edx, OFFSET promptHex
    call WriteString
    call hexInput
    call HexToDec
    call WriteDec
    call CrLf

    mov edx, OFFSET pressKey
    call WriteString
    call ReadChar

    exit
main ENDP

END main