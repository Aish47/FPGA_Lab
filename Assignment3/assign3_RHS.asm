.nolist
.include "m328Pdef.inc" ; Define device ATmega328P
.list

ldi r16,low(RAMEND) ; RAMEND address 0x08ff
out SPL,r16        ; Stack Pointer Low SPL>
ldi r16,high(RAMEND)
out SPH,r16

ldi r16,0b11111110
out DDRD,r16           ; pins D1 - D7 are set as output

sbi DDRB, 0

ldi r16, 0b00000101    ;  the last 3 bits define the prescaler, 101 => division by 1024
out TCCR0B, r16

ldi r18,0b00000000
out PortD,r18
out PortB,r18

ldi r25,0x07
load_table:
ldi r20, 0x08          ; conter register


ldi ZL, low(sev_seg<<1)
ldi ZH, high(sev_seg<<1)

loop:
    ldi r18,0b00000000
    out PortB,r18
    dec r20
   rcall DISPNUM
    brmi load_table
    rcall BITSEP
    
    and r13,r12           ;A.B
    and r11,r13	          ;A.B.C
    lsl r11
    lsl r11
    lsl r11
    lsl r11
    lsl r11    
    out PortB,r11         ; Display output in LED pin 13

    ldi r19, $32
    rcall DELAY

    rjmp loop

DELAY:         ;this is delay (function)
               ;times to run the loop = 64 for 1 second delay
    lp2:
        IN r16, TIFR0        ;tifr is timer interupt flag (8 bit timer runs 256 times)
        ldi r17, 0b00000010
        AND r16, r17         ;need second bit
        BREQ DELAY
        OUT TIFR0, r17       ;set tifr flag high
        dec r19
        brne lp2
    ret

DISPNUM:                     ; Routine for displaying number on seven segment
    lpm r17, Z+
    out PortD,r17
    ret
    
BITSEP:                      ; Routine for bit separation
    mov r21, r25     ;A LSB
    sub r21,r20
    andi r21,0x01
    mov r11,r21

    mov r22, r25     ;B
    sub r22,r20
    andi r22,0x02
    lsr r22
    mov r12,r22

    mov r23, r25     ;C MSB
    sub r23,r20
    andi r23,0x04
    lsr r23
    lsr r23
    mov r13,r23

    ret


ret
sev_seg: .DB  0x02, 0x9e, 0x24, 0x0c, 0x98,0x48, 0x40, 0x1e, 0x00, 0x08, 0x10, 0xc0, 0x62, 0x84, 0x60, 0x70
