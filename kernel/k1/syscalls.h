#ifndef K1_SYSCALLS_H
#define K1_SYSCALLS_H

#include "../k0/regs.h"

void set_handler(int, void (*)(regs*));
void syscall_common_handler(regs*);
void init_syscalls();

#endif
