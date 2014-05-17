#include <syscalls.h>
#include <output.h>

void print_tty(regs* r) {
    k0_print((char*)r->ecx);
}
