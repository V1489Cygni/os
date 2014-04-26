#include "syscalls.h"

#include "../../k0/output.h"

void print_tty(regs* r) {
    k0_print((char*)r->ecx);
}
