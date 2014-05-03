global jump_usermode

extern set_esp

jump_usermode:
    cli
    push esp
    call set_esp
    pop eax
    mov ax, 0x23
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov eax, [esp + 12]
    push dword 0x23
    push eax
    mov eax, [esp + 12]
    or eax, 0x200
    push eax
    push dword 0x1B
    push dword [esp + 24]
    iret
