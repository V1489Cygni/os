#ifndef K1_SYSCALLS_H
#define K1_SYSCALLS_H

#include <regs.h>

void set_handler(int, void (*)(regs*));
void syscall_common_handler(regs*);
void init_syscalls();

void get_char_tty(regs*);
void print_tty(regs*);
void exec(regs*);

#endif
