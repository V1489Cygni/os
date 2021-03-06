#include <syscalls.h>
#include <input.h>
#include <regs.h>

void get_char_tty(regs* r) {
    __asm__ __volatile__ ("sti");
    char c = get_char();
    char* res = (char*)r->ecx;
    *res = c;
}
