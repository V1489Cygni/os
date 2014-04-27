global set_paging_on

extern page_dir

set_paging_on:
    mov eax, page_dir
    mov cr3, eax
    mov eax, cr0
    or eax, 0x80000000
    mov cr0, eax
ret
