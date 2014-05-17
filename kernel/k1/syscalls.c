#include <syscalls.h>
#include <idt.h>
#include <regs.h>

#define SYSCALL_NUMBER 256

extern void syscall_primary_handler();

void (*syscall_handlers[SYSCALL_NUMBER])(regs*);

void set_handler(int number, void (*handler)(regs*)) {
    syscall_handlers[number] = handler;
}

void syscall_common_handler(regs* r) {
    void (*handler)(regs*) = syscall_handlers[r->eax];
    handler(r);
}

void init_syscalls() {
    set_handler(0, get_char_tty);
    set_handler(1, print_tty);
    set_handler(2, exec);
    set_idt_entry(0x80, (int)syscall_primary_handler, 0x08, 0xEE);
}
