org 100h

section .data
    judul db "=== SISTEM KALKULATOR PT ANUNG ===", 0Dh, 0Ah, '$' 

    num1 db 3
    num2 db 2

    tambah_msg db 0Dh, 0Ah, "Hasil Penjumlahan : $"
    kurang_msg db 0Dh, 0Ah, "Hasil Pengurangan : $"
    kali_msg   db 0Dh, 0Ah, "Hasil Perkalian   : $"
    bagi_msg   db 0Dh, 0Ah, "Hasil Pembagian   : $"
    sisa_msg   db 0Dh, 0Ah, "Sisa Pembagian    : $"

section .text
start:
    mov dx, judul
    mov ah, 09h
    int 21h

    ; =======================================================
    ; 1. BAGIAN PENJUMLAHAN
    ; =======================================================

    ; --- [AREA DIVISI PENGHITUNG] ---
    mov al, [num1]
    mov bl, [num2]
    add al, bl
    ; --------------------------------

    ; --- [AREA DIVISI PENCETAK] ---
    mov dx, tambah_msg
    mov ah, 09h
    int 21h
    
    mov dl, al
    add dl, '0' ;equivalent to add 30h
    mov ah, 02h
    int 21h
    ; ------------------------------


    ; =======================================================
    ; 2. BAGIAN PENGURANGAN
    ; =======================================================

    ; --- [AREA DIVISI PENGHITUNG] ---
    mov al, [num1]
    mov bl, [num2]
    sub al, bl
    ; --------------------------------

    ; --- [AREA DIVISI PENCETAK] ---
    mov dx, kurang_msg
    mov ah, 09h
    int 21h
    
    mov dl, al
    add dl, 30h
    mov ah, 02h
    int 21h
    ; ------------------------------


    ; =======================================================
    ; 3. BAGIAN PERKALIAN
    ; =======================================================

    ; --- [AREA DIVISI PENGHITUNG] ---
    mov al, [num1]
    mov bl, [num2]
    mul bl
    ; --------------------------------
    
    ; --- [AREA DIVISI PENCETAK] ---
    mov dx, kali_msg
    mov ah, 09h
    int 21h
    
    mov dl, al
    add dl, '0'
    mov ah, 02h
    int 21h
    ; ------------------------------


    ; =======================================================
    ; 4. BAGIAN PEMBAGIAN
    ; =======================================================

    ; --- [AREA DIVISI PENGHITUNG] ---
    xor ax, ax
    mov al, [num1]
    mov bl, [num2]
    div bl ; IMPORTANTTTT: writing div bl will causes a stroke for the computer or smtg. DO DIV BY ITS MEMORY SIZE. ig? idk
    
    push ax
    ; --------------------------------

    ; --- [AREA DIVISI PENCETAK] ---
    mov dx, bagi_msg
    mov ah, 09h
    int 21h
    
    mov dl, al
    add dl, '0'
    mov ah, 02h
    int 21h
    
    mov dx, sisa_msg
    mov ah, 09h
    int 21h

	pop ax
    mov dl, ah
    add dl, 30h
    mov ah, 02h
    int 21h
    ; ------------------------------

    ; Selesai
    mov ah, 4Ch
    int 21h