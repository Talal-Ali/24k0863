INCLUDE Irvine32.inc

.data
titleMsg BYTE "                                             ",0Dh,0Ah
         BYTE "       _____       .___                                     .___  _______               ___.                    _________               __                  ",0Dh,0Ah
         BYTE "      /  _  \    __| _/__  _______    ____   ____  ____   __| _/  \      \  __ __  _____\_ |__   ___________   /   _____/__.__. _______/  |_  ____   _____  ",0Dh,0Ah
         BYTE "     /  /_\  \  / __ |\  \/ /\__  \  /    \_/ ___\/ __ \ / __ |   /   |   \|  |  \/     \| __ \_/ __ \_  __ \  \_____  <   |  |/  ___/\   __\/ __ \ /     \ ",0Dh,0Ah
         BYTE "    /    |    \/ /_/ | \   /  / __ \|   |  \  \__\  ___// /_/ |  /    |    \  |  /  Y Y  \ \_\ \  ___/|  | \/  /        \___  |\___ \  |  | \  ___/|  Y Y  \",0Dh,0Ah
         BYTE "    \____|__  /\____ |  \_/  (____  /___|  /\___  >___  >____ |  \____|__  /____/|__|_|  /___  /\___  >__|    /_______  / ____/____  > |__|  \___  >__|_|  /",0Dh,0Ah
         BYTE "            \/      \/            \/     \/     \/    \/     \/          \/            \/    \/     \/                \/\/         \/            \/      \/ ",0Dh,0Ah,0
         
menuMsg     BYTE   "._______________________.",0Dh,0Ah
            BYTE   "|  CONVERSION OPTIONS   |",0Dh,0Ah
            BYTE   "|_______________________| ", 0Dh,0Ah
            BYTE   "|1.| Binary to Decimal  |",0Dh,0Ah
            BYTE   "|2.| Octal to Decimal   |",0Dh,0Ah
            BYTE   "|3.| Hex   to Decimal   |",0Dh,0Ah
            BYTE   "|4.| Decimal to Binary  |",0Dh,0Ah
            BYTE   "|5.| Decimal to Octal   |",0Dh,0Ah
            BYTE   "|6.| Decimal to Hex     |",0Dh,0Ah
            BYTE   "|7.| Bitwise AND        |",0Dh,0Ah
            BYTE   "|8.| Bitwise OR         |",0Dh,0Ah
            BYTE   "|9.| Bitwise XOR        |",0Dh,0Ah
            BYTE   "|10| Bitwise NOT        |",0Dh,0Ah
            BYTE   "|11| Float to Binary    |",0Dh,0Ah
            BYTE   "|0.| Exit to Menu       |",0Dh,0Ah
            BYTE   "+-----------------------+", 0Dh,0Ah
            BYTE    "Choose an option: ",0Dh,0Ah,0

promptBinInput BYTE "Enter a Binary Number (0s and 1s only): ",0
promptOctInput BYTE "Enter an Octal Number (0-7 only): ",0
promptHexInput BYTE "Enter a Hexadecimal Number (0-9, A-F): ",0
promptDecInput BYTE "Enter a Decimal Number: ",0
promptFloatInput BYTE "Enter a Floating-point Number: ",0
promptNum1     BYTE "Enter first number: ",0
promptNum2     BYTE "Enter second number: ",0

outLabelBin      BYTE "+--- BINARY TO DECIMAL -----------+",13,10
                 BYTE "| Result: ",0
outLabelOct      BYTE "+--- OCTAL TO DECIMAL ------------+",13,10
                 BYTE "| Result: ",0
outLabelHex      BYTE "+--- HEX TO DECIMAL --------------+",13,10
                 BYTE "| Result: ",0

outLabelDecToBin BYTE "+------- DECIMAL TO BINARY --------------+",13,10
                 BYTE "| Result: ",0
outLabelDecToOct BYTE "+--- DECIMAL TO OCTAL ------------+",13,10
                 BYTE "| Result: ",0
outLabelDecToHex BYTE "+--- DECIMAL TO HEX --------------+",13,10
                 BYTE "| Result: ",0
outLabelFloatToBin BYTE "+--- FLOAT TO BINARY -------------+",13,10
                 BYTE "| Result: ",0

outLabelAND      BYTE "+--- BITWISE AND -----------------+",13,10
                 BYTE "| Result: ",0
outLabelOR       BYTE "+--- BITWISE OR ------------------+",13,10
                 BYTE "| Result: ",0
outLabelXOR      BYTE "+--- BITWISE XOR -----------------+",13,10
                 BYTE "| Result: ",0
outLabelNOT      BYTE "+--- BITWISE NOT -----------------+",13,10
                 BYTE "| Result: ",0

resultBoxBottom  BYTE 13,10,"+---------------------------------+",0

errInvalidBin  BYTE "Error: Invalid Binary Input!",0Dh,0Ah,0
errInvalidOct  BYTE "Error: Invalid Octal Input!",0Dh,0Ah,0
errInvalidHex  BYTE "Error: Invalid Hex Input!",0Dh,0Ah,0
errInvalidDec  BYTE "Error: Invalid Decimal Input!",0Dh,0Ah,0

promptContinue  BYTE 0Dh,0Ah,"Press any key to return to menu...",0

binString  BYTE 33 DUP(0)
octString  BYTE 32 DUP(0)
hexString  BYTE 32 DUP(0)
tempString BYTE 33 DUP(0)
floatBinString BYTE 35 DUP(0)  ; 32 bits + sign + decimal point
inp        DWORD 0    
num1       DWORD 0
num2       DWORD 0
floatVal   REAL4 ?

;animations
typeDelay DWORD 1

loadingFrames BYTE "Converting... |", 0
              BYTE "Converting... /", 0
              BYTE "Converting... -", 0
              BYTE "Converting... \", 0

clearLineStr BYTE 13, "                            ", 13, 0

.code

; Helper: clear buffers
clearBuffer PROC
    push eax
    push ecx
    push edi

    lea edi, binString
    mov ecx, LENGTHOF binString
    xor al, al
    rep stosb

    lea edi, octString
    mov ecx, LENGTHOF octString
    rep stosb

    lea edi, hexString
    mov ecx, LENGTHOF hexString
    rep stosb

    lea edi, tempString
    mov ecx, LENGTHOF tempString
    rep stosb

    lea edi, floatBinString
    mov ecx, LENGTHOF floatBinString
    rep stosb

    pop edi
    pop ecx
    pop eax
    ret
clearBuffer ENDP

;Animation

TypeWrite PROC
    ; EDX = string offset
    pushad
    mov esi, edx
type_loop:
    mov al, [esi]
    cmp al, 0
    je type_done
    call WriteChar
    mov eax, typeDelay
    call Delay
    inc esi
    jmp type_loop
type_done:
    popad
    ret
TypeWrite ENDP

LoadingAnimation PROC
    push ecx
    push edx
    
    mov ecx, 6           ; Number of animation cycles
    
animation_loop:
    ; Frame 1
    mov edx, OFFSET loadingFrames
    call WriteString
    mov eax, 100
    call Delay
    call ClearLine
    
    ; Frame 2
    add edx, 16
    call WriteString
    mov eax, 100
    call Delay
    call ClearLine
    
    ; Frame 3
    add edx, 16
    call WriteString
    mov eax, 100
    call Delay
    call ClearLine
    
    ; Frame 4
    add edx, 16
    call WriteString
    mov eax, 100
    call Delay
    call ClearLine
    
    loop animation_loop
    
    pop edx
    pop ecx
    ret
LoadingAnimation ENDP

ClearLine PROC
    push edx
    mov edx, OFFSET clearLineStr
    call WriteString
    pop edx
    ret
ClearLine ENDP

PulseTitle PROC
    push ecx
    mov ecx, 3         ; Number of pulses
    
pulse_loop:
    ; Change to dark red AND redraw
    mov eax, red + (black * 16)
    call SetTextColor
    
    ; Clear and redraw to see color change
    call ClrScr
    mov edx, OFFSET titleMsg
    call WriteString
    mov eax, 300
    call Delay
    
    ; Change back to bright red AND redraw
    mov eax, lightRed + (black * 16)
    call SetTextColor
    
    ; Clear and redraw again
    call ClrScr
    mov edx, OFFSET titleMsg
    call WriteString
    mov eax, 300
    call Delay
    
    loop pulse_loop
    
    pop ecx
    ret
PulseTitle ENDP




; Binary -> Decimal (with signed support)
; returns decimal in EAX, -1 on invalid
BinToDec PROC
    push ebx
    push esi
    push ecx
    push edx

    mov esi, OFFSET binString
    xor eax, eax
    xor ecx, ecx
    
    ; Count the number of bits and validate
count_bits:
    mov bl, [esi]
    cmp bl, 0
    je count_done
    cmp bl, 13
    je count_done
    cmp bl, 10
    je count_done
    cmp bl, ' '
    je count_skip
    cmp bl, '0'
    jb bin_invalid
    cmp bl, '1'
    ja bin_invalid
    inc ecx
count_skip:
    inc esi
    jmp count_bits
count_done:

    cmp ecx, 0
    je bin_invalid
    
    mov esi, OFFSET binString
    
    ; If we have exactly 32 bits and first bit is '1', treat as signed
    cmp ecx, 32
    jne unsigned_bin
    mov bl, [esi]
    cmp bl, '1'
    jne unsigned_bin
    
    ; Signed binary (2's complement) - simple approach
    xor eax, eax
    
signed_bin_loop:
    mov bl, [esi]
    cmp bl, 0
    je signed_done
    cmp bl, 13
    je signed_done
    cmp bl, 10
    je signed_done
    cmp bl, ' '
    je signed_next
    
    shl eax, 1
    sub bl, '0'
    add al, bl
    
signed_next:
    inc esi
    jmp signed_bin_loop

signed_done:
    jmp bin_done

unsigned_bin:
    ; Regular unsigned binary conversion
    mov esi, OFFSET binString
    xor eax, eax
    
bin_loop:
    mov bl, [esi]
    cmp bl, 0
    je bin_done
    cmp bl, 13
    je bin_done
    cmp bl, 10
    je bin_done
    cmp bl, ' '
    je bin_next

    shl eax, 1
    sub bl, '0'
    add al, bl

bin_next:
    inc esi
    jmp bin_loop

bin_invalid:
    mov eax, -1

bin_done:
    pop edx
    pop ecx
    pop esi
    pop ebx
    ret
BinToDec ENDP

; Octal -> Decimal (unsigned only)
; returns decimal in EAX, -1 on invalid
OctToDec PROC
    push ebx
    push esi

    xor eax, eax
    mov esi, OFFSET octString

o_loop:
    mov bl, [esi]
    cmp bl, 0
    je o_done
    cmp bl, 13
    je o_done
    cmp bl, 10
    je o_done
    cmp bl, ' '
    je o_next

    cmp bl, '0'
    jb o_invalid
    cmp bl, '7'
    ja o_invalid

    shl eax, 3
    sub bl, '0'
    add al, bl

o_next:
    inc esi
    jmp o_loop

o_invalid:
    mov eax, -1

o_done:
    pop esi
    pop ebx
    ret
OctToDec ENDP

; Hex -> Decimal (with signed support)
; returns decimal in EAX, -1 on invalid
; Hex -> Decimal (with signed support)
; returns decimal in EAX, -1 on invalid
HexToDec PROC
    push ebx
    push esi
    push ecx

    mov esi, OFFSET hexString
    xor eax, eax
    xor ecx, ecx
    
    ; Count the number of hex digits
count_hex_digits:
    mov bl, [esi]
    cmp bl, 0
    je hex_count_done
    cmp bl, 13
    je hex_count_done
    cmp bl, 10
    je hex_count_done
    cmp bl, ' '
    je hex_count_skip
    inc ecx
hex_count_skip:
    inc esi
    jmp count_hex_digits
hex_count_done:

    cmp ecx, 0
    je hex_invalid
    
    mov esi, OFFSET hexString
    
    ; If we have exactly 8 digits and first digit is >= '8', treat as signed
    cmp ecx, 8
    jne unsigned_hex
    mov bl, [esi]
    cmp bl, '8'
    jb unsigned_hex
    cmp bl, '9'
    jbe signed_hex
    cmp bl, 'A'
    jb check_hex_lower
    cmp bl, 'F'
    jbe signed_hex
check_hex_lower:
    cmp bl, 'a'
    jb hex_invalid
    cmp bl, 'f'
    jbe signed_hex
    jmp unsigned_hex

signed_hex:
    ; Signed hex (2's complement) - convert normally then adjust
    xor eax, eax
    
hex_loop_signed:
    mov bl, [esi]
    cmp bl, 0
    je hex_signed_adjust
    cmp bl, 13
    je hex_signed_adjust
    cmp bl, 10
    je hex_signed_adjust
    cmp bl, ' '
    je hex_next_signed

    cmp bl, '0'
    jb hex_invalid
    cmp bl, '9'
    jbe hex_0_9_signed
    cmp bl, 'A'
    jb hex_check_low_signed
    cmp bl, 'F'
    jbe hex_A_Fs_signed
hex_check_low_signed:
    cmp bl, 'a'
    jb hex_invalid
    cmp bl, 'f'
    jbe hex_a_f_signed
    jmp hex_invalid

hex_0_9_signed:
    sub bl, '0'
    jmp hex_absorb_signed

hex_A_Fs_signed:
    sub bl, 'A'
    add bl, 10
    jmp hex_absorb_signed

hex_a_f_signed:
    sub bl, 'a'
    add bl, 10

hex_absorb_signed:
    shl eax, 4
    add al, bl

hex_next_signed:
    inc esi
    jmp hex_loop_signed

hex_signed_adjust:
    ; The value in EAX is the 2's complement representation
    ; Just return it as is - it will be interpreted correctly as signed
    jmp hex_done

unsigned_hex:
    ; Regular unsigned hex conversion
    mov esi, OFFSET hexString
    xor eax, eax
    
hex_loop:
    mov bl, [esi]
    cmp bl, 0
    je hex_done
    cmp bl, 13
    je hex_done
    cmp bl, 10
    je hex_done
    cmp bl, ' '
    je hex_next

    cmp bl, '0'
    jb hex_invalid
    cmp bl, '9'
    jbe hex_0_9
    cmp bl, 'A'
    jb hex_check_low
    cmp bl, 'F'
    jbe hex_A_Fs
hex_check_low:
    cmp bl, 'a'
    jb hex_invalid
    cmp bl, 'f'
    jbe hex_a_f
    jmp hex_invalid

hex_0_9:
    sub bl, '0'
    jmp hex_absorb

hex_A_Fs:
    sub bl, 'A'
    add bl, 10
    jmp hex_absorb

hex_a_f:
    sub bl, 'a'
    add bl, 10

hex_absorb:
    shl eax, 4
    add al, bl

hex_next:
    inc esi
    jmp hex_loop

hex_invalid:
    mov eax, -1

hex_done:
    pop ecx
    pop esi
    pop ebx
    ret
HexToDec ENDP

; Decimal -> Binary (supports both signed and unsigned)
; uses global 'inp' as input
DecToBin PROC
    push eax
    push ebx
    push ecx
    push edi
    push edx

    mov eax, inp
    mov edx, OFFSET outLabelDecToBin
    call WriteString

    lea edi, binString
    mov ecx, 32         ; 32 bits

db_loop:
    mov ebx, eax
    and ebx, 80000000h  ; get MSB
    shr ebx, 31
    add bl, '0'
    mov BYTE PTR [edi], bl
    inc edi
    shl eax, 1
    dec ecx
    jnz db_loop

    mov BYTE PTR [edi], 0
    lea edx, binString
    call WriteString
    call Crlf

    pop edx
    pop edi
    pop ecx
    pop ebx
    pop eax
    ret
DecToBin ENDP

; Decimal -> Hex (supports both signed and unsigned)
; uses global 'inp' as input
DecToHex PROC
    push eax
    push ebx
    push ecx
    push edi
    push edx

    mov eax, inp
    mov edx, OFFSET outLabelDecToHex
    call WriteString

    lea edi, hexString
    mov ecx, 8          ; 8 hex digits

dh_loop:
    mov ebx, eax
    and ebx, 0Fh
    cmp bl, 9
    jle dh_digit
    add bl, 7
dh_digit:
    add bl, '0'
    mov BYTE PTR [edi+ecx-1], bl
    shr eax, 4
    dec ecx
    jnz dh_loop

    mov BYTE PTR [edi+8], 0
    lea edx, hexString
    call WriteString
    call Crlf

    pop edx
    pop edi
    pop ecx
    pop ebx
    pop eax
    ret
DecToHex ENDP

; Decimal -> Octal (supports both signed and unsigned)
; uses global 'inp' as input
DecToOct PROC
    push eax
    push ebx
    push ecx
    push edi

    mov eax, inp
    mov edx, OFFSET outLabelDecToOct
    call WriteString

    lea edi, octString
    mov ecx, 11         ; 32-bit octal digits

do_loop:
    mov ebx, eax
    and ebx, 7
    add bl, '0'
    mov BYTE PTR [edi+ecx-1], bl
    shr eax, 3
    dec ecx
    jnz do_loop

    mov BYTE PTR [edi+11], 0
    lea edx, octString
    call WriteString
    call Crlf

    pop edi
    pop ecx
    pop ebx
    pop eax
    ret
DecToOct ENDP

; Floating-point to Binary (IEEE 754 single precision)
; uses global 'floatVal' as input
FloatToBin PROC
    push eax
    push ebx
    push ecx
    push edi
    push edx

    mov edx, OFFSET outLabelFloatToBin
    call WriteString

    ; Get the binary representation of the float
    mov eax, floatVal  ; Move the float value into EAX (this gets the IEEE 754 bits)
    
    lea edi, floatBinString
    mov ecx, 32         ; 32 bits for single precision float

    ; Format: S EEEEEEEE MMMMMMMMMMMMMMMMMMMMMMM
    ; Sign (1 bit) | Exponent (8 bits) | Mantissa (23 bits)
    
fb_loop:
    mov ebx, eax
    and ebx, 80000000h  ; get MSB
    shr ebx, 31
    add bl, '0'
    mov BYTE PTR [edi], bl
    inc edi
    
    ; Add spaces for readability: after sign bit and after exponent
    cmp ecx, 24
    jne fb_no_space1
    mov BYTE PTR [edi], ' '
    inc edi
fb_no_space1:
    
    cmp ecx, 9
    jne fb_no_space2
    mov BYTE PTR [edi], ' '
    inc edi
fb_no_space2:
    
    shl eax, 1
    dec ecx
    jnz fb_loop

    mov BYTE PTR [edi], 0
    
    ; Add labels for the parts
    call Crlf
    mov edx, OFFSET floatPartsLabel
    call WriteString
    call Crlf
    
    lea edx, floatBinString
    call WriteString
    
    ; Show the interpretation
    call Crlf
    mov edx, OFFSET floatInterpretation
    call WriteString
    
    ; Extract and show sign
    mov eax, floatVal
    and eax, 80000000h
    shr eax, 31
    call WriteDec
    call Crlf
    
    ; Extract and show exponent
    mov edx, OFFSET exponentLabel
    call WriteString
    mov eax, floatVal
    and eax, 7F800000h
    shr eax, 23
    call WriteDec
    call Crlf
    
    ; Extract and show mantissa
    mov edx, OFFSET mantissaLabel
    call WriteString
    mov eax, floatVal
    and eax, 007FFFFFh
    call WriteHex
    call Crlf

    pop edx
    pop edi
    pop ecx
    pop ebx
    pop eax
    ret
FloatToBin ENDP

; Bitwise AND operation
BitwiseAND PROC
    push eax
    push ebx
    
    mov edx, OFFSET promptNum1
    call WriteString
    call ReadInt
    mov num1, eax
    
    mov edx, OFFSET promptNum2
    call WriteString
    call ReadInt
    mov num2, eax
    
    mov eax, num1
    and eax, num2
    
    mov edx, OFFSET outLabelAND
    call WriteString
    call WriteInt
    call Crlf
    
    ; Show binary representation
    mov inp, eax
    call DecToBin
    
    pop ebx
    pop eax
    ret
BitwiseAND ENDP

; Bitwise OR operation
BitwiseOR PROC
    push eax
    push ebx
    
    mov edx, OFFSET promptNum1
    call WriteString
    call ReadInt
    mov num1, eax
    
    mov edx, OFFSET promptNum2
    call WriteString
    call ReadInt
    mov num2, eax
    
    mov eax, num1
    or eax, num2
    
    mov edx, OFFSET outLabelOR
    call WriteString
    call WriteInt
    call Crlf
    
    ; Show binary representation
    mov inp, eax
    call DecToBin
    
    pop ebx
    pop eax
    ret
BitwiseOR ENDP

; Bitwise XOR operation
BitwiseXOR PROC
    push eax
    push ebx
    
    mov edx, OFFSET promptNum1
    call WriteString
    call ReadInt
    mov num1, eax
    
    mov edx, OFFSET promptNum2
    call WriteString
    call ReadInt
    mov num2, eax
    
    mov eax, num1
    xor eax, num2
    
    mov edx, OFFSET outLabelXOR
    call WriteString
    call WriteInt
    call Crlf
    
    ; Show binary representation
    mov inp, eax
    call DecToBin
    
    pop ebx
    pop eax
    ret
BitwiseXOR ENDP

; Bitwise NOT operation
BitwiseNOT PROC
    push eax
    push ebx
    
    mov edx, OFFSET promptNum1
    call WriteString
    call ReadInt
    mov num1, eax
    
    mov eax, num1
    not eax
    
    mov edx, OFFSET outLabelNOT
    call WriteString
    call WriteInt
    call Crlf
    
    ; Show binary representation
    mov inp, eax
    call DecToBin
    
    pop ebx
    pop eax
    ret
BitwiseNOT ENDP

; UI: show prompts and perform conversions
ShowAndPause PROC
    ; print continue prompt and wait
    mov edx, OFFSET promptContinue
    call WriteString
    call ReadChar
    call ClrScr
    ret
ShowAndPause ENDP

; Data for float display
floatPartsLabel BYTE "Format: S EEEEEEEE MMMMMMMMMMMMMMMMMMMMMMM",0Dh,0Ah,0
floatInterpretation BYTE "Interpretation:",0Dh,0Ah,"Sign: ",0
exponentLabel BYTE "Exponent: ",0
mantissaLabel BYTE "Mantissa: 0x",0

main PROC
    call Clrscr
MainMenuLoop:
    
    mov eax, lightRed + (black * 16)  ; Bright red title
    call SetTextColor

    mov edx, OFFSET titleMsg
    call writestring
    call PulseTitle

    mov eax, lightgreen + (black * 16)  ; Reset to default
    call SetTextColor

    mov edx, OFFSET menuMsg
     call TypeWrite          ; Changed from WriteString
     call Crlf

    ; read choice
    call ReadInt
    mov ebx, eax    ; choice

    cmp ebx, 1
    je OptBinToDec
    cmp ebx, 2
    je OptOctToDec
    cmp ebx, 3
    je OptHexToDec
    cmp ebx, 4
    je OptDecToBin
    cmp ebx, 5
    je OptDecToOct
    cmp ebx, 6
    je OptDecToHex
    cmp ebx, 7
    je OptBitwiseAND
    cmp ebx, 8
    je OptBitwiseOR
    cmp ebx, 9
    je OptBitwiseXOR
    cmp ebx, 10
    je OptBitwiseNOT
    cmp ebx, 11
    je OptFloatToBin
    cmp ebx, 0
    je ExitToMain
    ; invalid -> loop
    mov edx, OFFSET errInvalidDec
    call WriteString
    call Crlf
    jmp MainMenuLoop

OptBinToDec:
    call clearBuffer
    mov edx, OFFSET promptBinInput
    call WriteString
    mov edx, OFFSET binString
    mov ecx, SIZEOF binString
    call ReadString

    call LoadingAnimation

    call BinToDec
    cmp eax, -1
    je BinErr
    mov edx, OFFSET outLabelBin
    call WriteString
    call WriteInt

    mov edx, OFFSET resultBoxBottom 
    call WriteString                
    call Crlf
    call ShowAndPause
    jmp MainMenuLoop

BinErr:
    mov edx, OFFSET errInvalidBin
    call WriteString
    call ShowAndPause
    jmp MainMenuLoop

OptOctToDec:
    call clearBuffer
    mov edx, OFFSET promptOctInput
    call WriteString
    mov edx, OFFSET octString
    mov ecx, SIZEOF octString

    call ReadString
    call LoadingAnimation

    call OctToDec
    cmp eax, -1
    je OctErr
    mov edx, OFFSET outLabelOct
    call WriteString
    call WriteDec

    mov edx, OFFSET resultBoxBottom 
    call WriteString
    call Crlf
    call ShowAndPause
    jmp MainMenuLoop

OctErr:
    mov edx, OFFSET errInvalidOct
    call WriteString
    call ShowAndPause
    jmp MainMenuLoop

OptHexToDec:
    call clearBuffer
    mov edx, OFFSET promptHexInput
    call WriteString
    mov edx, OFFSET hexString
    mov ecx, SIZEOF hexString

    call ReadString
    call LoadingAnimation

    call HexToDec
    cmp eax, -1
    je HexErr
    mov edx, OFFSET outLabelHex
    call Writestring
    call WriteInt

    mov edx, OFFSET resultBoxBottom 
    call WriteString
    call Crlf
    call ShowAndPause
    jmp MainMenuLoop

HexErr:
    mov edx, OFFSET errInvalidHex
    call WriteString
    call ShowAndPause
    jmp MainMenuLoop

OptDecToBin:
    call clearBuffer
    mov edx, OFFSET promptDecInput
    call WriteString
    call ReadInt
    mov inp, eax
    call LoadingAnimation
    call DecToBin
    mov edx, OFFSET resultBoxBottom 
    call WriteString
    call ShowAndPause
    jmp MainMenuLoop

OptDecToOct:
    call clearBuffer
    mov edx, OFFSET promptDecInput
    call WriteString
    call ReadInt
    mov inp, eax
    call LoadingAnimation
    call DecToOct
    mov edx, OFFSET resultBoxBottom 
    call WriteString
    call ShowAndPause
    jmp MainMenuLoop

OptDecToHex:
    call clearBuffer
    mov edx, OFFSET promptDecInput
    call WriteString
    call ReadInt
    mov inp, eax
    call LoadingAnimation
    call DecToHex
    mov edx, OFFSET resultBoxBottom 
    call WriteString
    call ShowAndPause
    jmp MainMenuLoop

OptBitwiseAND:
    call clearBuffer
    call BitwiseAND
    mov edx, OFFSET resultBoxBottom 
    call WriteString
    call ShowAndPause
    jmp MainMenuLoop

OptBitwiseOR:
    call clearBuffer
    call BitwiseOR
    mov edx, OFFSET resultBoxBottom 
    call WriteString
    call ShowAndPause
    jmp MainMenuLoop

OptBitwiseXOR:
    call clearBuffer
    call BitwiseXOR
    mov edx, OFFSET resultBoxBottom 
    call WriteString
    call ShowAndPause
    jmp MainMenuLoop

OptBitwiseNOT:
    call clearBuffer
    call BitwiseNOT
    mov edx, OFFSET resultBoxBottom 
    call WriteString
    call ShowAndPause
    jmp MainMenuLoop

OptFloatToBin:
    call clearBuffer
    mov edx, OFFSET promptFloatInput
    call WriteString
    call ReadFloat    ; Read floating-point value
    fstp floatVal     ; Store the float value
    call LoadingAnimation
    call FloatToBin
    mov edx, OFFSET resultBoxBottom 
    call WriteString
    call ShowAndPause
    jmp MainMenuLoop

ExitToMain:
    call ClrScr
    ret

main ENDP

END main