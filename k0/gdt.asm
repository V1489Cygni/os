global load_gdt

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
