global start

extern init_main

align 4
dd 0xC0DEAA55

start:
    call init_main
