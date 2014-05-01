#include "scheduler.h"
#include "../k0/output.h"
#include "../k0/gdt.h"

proc_info queue[10];
int last = 0;

extern gdt_entry gdt;

void test_f2() {
    k0_print("|\n");
    k0_print_int((int)&gdt);
    //k0_print("A");
    //__asm__ __volatile__ ("cli");
    k0_print("B");
    __asm__ volatile ("hlt");
    for(;;) {}
}

extern void jump_usermode(int, int, int);

void execute_in_usermode(proc_info p) {
    jump_usermode(p.r.eflags, p.r.eip, p.r.esp);
}

void start_task(int addr) {
    queue[last].r.eip = addr;
    queue[last].r.esp = 0x40000000;
    execute_in_usermode(queue[last++]);
}
