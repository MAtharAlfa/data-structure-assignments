org 100h

section .data
    msg1 db "Hello, World!", 0Dh, '$'   ; CR only, no LF
    msg2 db "Hi", 0Dh, '$'

section .text
start:
    mov ah, 09h
    mov dx, msg1
    int 21h

    mov ah, 09h
    mov dx, msg2        ; print again
    int 21h

    mov ah, 4Ch
    int 21h