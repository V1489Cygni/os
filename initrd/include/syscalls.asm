global sc_get_char
global sc_print

sc_get_char:
    mov eax, 0
    mov ecx, [esp + 4]
    int 80h
ret

sc_print:
    mov eax, 1
    mov ecx, [esp + 4]
    int 80h
ret

sc_exec:
    mov eax, 2
    mov ecx, [esp + 4]
    int 80h
ret
