global jump_usermode

extern set_esp
extern test_f2

test_f:
    jmp $

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
    mov eax, esp;[esp + 4]
    push dword 0x23
    push eax
    ;mov eax, [esp + 12]
    pushf
    pop eax
    or eax, 0x200
    push eax
    push dword 0x1B
    push dword test_f2;[esp + 8]
    iretd
