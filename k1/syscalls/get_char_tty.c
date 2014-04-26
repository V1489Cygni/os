#include "syscalls.h"

#include "../input.h"
#include "../../k0/regs.h"

void get_char_tty(regs* r) {
    __asm__ __volatile__ ("sti");
    char c = get_char();
    int* res = (int*)r->ecx;
    *res = (int)c;
}
