; =============================================================================
;  melody.asm — PC Speaker Melody Player for MS-DOS
;  Assembles to a .COM file (flat binary, org 0x100)
;
;  Assemble:  nasm -f bin melody.asm -o melody.com
;  Run:       melody.com   (in DOSBox or real DOS)
;  Exit:      plays the melody once, then returns to DOS
; =============================================================================

    org  100h          ; COM files always start at offset 0x100 in segment

; -----------------------------------------------------------------------------
;  HOW THE PC SPEAKER WORKS
;
;  The IBM PC has a Programmable Interval Timer (Intel 8253/8254) with three
;  channels.  Channel 2 is wired to the speaker.
;
;  To play a tone at frequency F (Hz):
;    divisor = 1193180 / F        (1193180 Hz is the PIT input clock)
;
;  Write to ports:
;    43h  — PIT control register
;    42h  — Channel 2 data (divisor, low byte first, then high byte)
;    61h  — PC port B; bit 0 = gate channel 2, bit 1 = connect to speaker
;
;  To silence:
;    Clear bits 0 and 1 of port 61h.
; -----------------------------------------------------------------------------

; =============================================================================
;  ENTRY POINT
; =============================================================================
start:
    mov  si, melody         ; SI = pointer to the melody table

.play_loop:
    ; ---- Load note frequency (word) and duration (word) --------------------
    lodsw                   ; AX = frequency (Hz) from [SI], SI += 2
    cmp  ax, 0              ; frequency == 0 means "end of melody"
    je   .done

    mov  bx, ax             ; save frequency in BX
    lodsw                   ; AX = duration in timer ticks (~18.2 ticks/sec)
    mov  cx, ax             ; save duration in CX

    ; ---- Is this a rest? (frequency == 1 is our REST sentinel) -------------
    cmp  bx, 1
    je   .rest

    ; ---- Program the PIT channel 2 -----------------------------------------
    ;  Control word 0xB6:
    ;    bits 7-6 = 10   → select channel 2
    ;    bits 5-4 = 11   → access mode: low byte then high byte
    ;    bits 3-1 = 011  → mode 3 (square wave generator)
    ;    bit  0   = 0    → binary (not BCD)
    mov  al, 0B6h
    out  43h, al            ; write control word to PIT

    ; Compute divisor = 1193180 / frequency
    ; 1193180 in hex is 0x123CC — fits in 32 bits but not 16.
    ; We use DX:AX division.
    mov  ax, 34DCh         ; low word of 1193180  (0x1_34DC in 32-bit)
    mov  dx, 012h         ; high word            (0x12 * 65536 + 0x34DC = 1193180)
    div  bx                 ; AX = quotient (divisor), DX = remainder

    out  42h, al            ; send low byte of divisor to channel 2
    mov  al, ah
    out  42h, al            ; send high byte of divisor to channel 2

    ; ---- Enable the speaker -------------------------------------------------
    in   al, 61h            ; read current value of port B
    or   al, 0x03           ; set bits 0 (gate PIT ch2) and 1 (speaker enable)
    out  61h, al            ; write back — speaker starts playing!

    ; ---- Wait for 'cx' timer ticks -----------------------------------------
    call wait_ticks         ; delay using BIOS tick counter

    ; ---- Silence the speaker ------------------------------------------------
    in   al, 61h
    and  al, 0xFC           ; clear bits 0 and 1 (gate off, speaker off)
    out  61h, al

    ; ---- Short gap between notes (prevents notes from blurring together) ----
    mov  cx, 1
    call wait_ticks

    jmp  .play_loop         ; next note

.rest:
    ; A rest: speaker stays silent, we just wait
    call wait_ticks         ; CX already holds rest duration
    jmp  .play_loop

.done:
    ; ---- Return to DOS ------------------------------------------------------
    mov  ax, 4Ch         ; AH=4Ch: terminate process, AL=0: exit code 0
    int  21h


; =============================================================================
;  wait_ticks — busy-wait for CX BIOS timer ticks (1 tick ≈ 54.9 ms)
;
;  The BIOS tick counter lives at segment 0x0040, offset 0x006C (a dword).
;  INT 1Ah / AH=00h returns the low word in CX and high word in DX, but
;  reading the memory location directly is simpler for a tight loop.
;
;  Strategy: record the start tick, spin until (current - start) >= CX.
; =============================================================================
wait_ticks:
    push ax
    push bx
    push dx
    push es

    mov  ax, 0040h         ; BIOS data segment
    mov  es, ax

    mov  dx, [es:0x6C]      ; read current low-word of tick counter → DX (start)

.spin:
    mov  bx, [es:0x6C]      ; read current tick
    sub  bx, dx             ; elapsed = current − start
    cmp  bx, cx             ; elapsed >= requested duration?
    jb   .spin              ; no → keep spinning

    pop  es
    pop  dx
    pop  bx
    pop  ax
    ret


; =============================================================================
;  MELODY TABLE
;
;  Each entry is two words:
;    DW  frequency_hz, duration_ticks
;
;  Special values:
;    frequency = 0  → end of melody (sentinel)
;    frequency = 1  → rest (silence for duration_ticks)
;
;  Durations use ~18.2 ticks per second:
;    quarter note at 120 BPM ≈ 9 ticks
;    eighth  note at 120 BPM ≈ 5 ticks
;
;  This plays the opening of "Twinkle Twinkle Little Star"
;  (easy to verify by ear, fun to modify!)
;
;  Note frequencies (equal temperament, A4=440 Hz):
;    C4=262  D4=294  E4=330  F4=349  G4=392  A4=440  B4=494  C5=523
; =============================================================================

; Helper macro: NOTE freq, dur_ticks
%define Q   9       ; quarter note  (~120 BPM)
%define H   18      ; half note
%define E   5       ; eighth note
%define REST 1      ; rest sentinel

melody:
    dw  370, Q          ; F#4  
    dw  440, H          ; A4  
    dw  220, E          ; A3  
    dw  247, H          ; B3  
    
    dw  REST, Q         ; short rest

    dw  277, Q          ; C#4 
    dw  330, E          ; E4  
    dw  311, E          ; D#4
    dw  294, E          ; D4 
    dw  554, Q          ; C5#  
    dw  523, 3          ; C5
    dw  494, 3          ; B4  
    dw  440, H          ; A4
    
    dw  494, E          ; B4
    dw  523, Q          ; C5
    dw  494, 3          ; B4
    dw  440, 3          ; A4  
    dw  494, 3          ; B4

    dw  220, E          ; A3
    dw  247, E          ; B3
    dw  277, H          ; C#4

    dw  294, Q          ; D4
    dw  294, Q          ; D4
    dw  277, E          ; C#4
    dw  370, H          ; F#4

    dw  REST, H         ; short rest

    
    dw  370, Q          ; F#4  
    dw  440, H          ; A4  
    dw  220, E          ; A3  
    dw  247, H          ; B3  
    
    dw  REST, E         ; short rest

    dw  277, Q          ; C#4 
    dw  330, E          ; E4  
    dw  311, E          ; D#4
    dw  294, E          ; D4 
    dw  554, Q          ; C5#  
    dw  523, 3          ; C5
    dw  494, 3          ; B4  
    dw  440, H          ; A4
    
    dw  494, E          ; B4
    dw  523, Q          ; C5
    dw  494, 3          ; B4
    dw  440, 3          ; A4  
    dw  494, 3          ; B4

    dw  220, E          ; A3
    dw  247, E          ; B3
    dw  277, H          ; C#4

    dw  277, Q          ; C#4
    dw  294, Q          ; D4
    dw  330, E          ; E4
    dw  294, H          ; D4

    dw  0, 0            ; ← END OF MELODY sentinel
