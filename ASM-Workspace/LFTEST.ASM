org 100h

section .data
    msg1 db "Hello, World!", 0Ah, '$'
    msg2 db "Hi", 0Ah, '$'

section .text
start:
    mov ah, 09h
    mov dx, msg1
    int 21h

    mov ah, 09h
    mov dx, msg2
    int 21h

    mov ah, 4Ch
    int 21h