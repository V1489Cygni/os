global load_gdt
global load_tss

extern gp

load_gdt:
    lgdt [gp]
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    jmp 0x08:load_cs
load_cs:
    ret

load_tss:
    mov ax, 0x2B
    ltr ax
ret
