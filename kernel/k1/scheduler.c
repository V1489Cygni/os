#include <scheduler.h>

proc_info queue[10];
int last = 0;

extern void jump_usermode(int, int, int);

void execute_in_usermode(proc_info p) {
    jump_usermode(p.r.eflags, p.r.eip, p.r.esp);
}

void start_task(int addr) {
    queue[last].r.eip = addr;
    queue[last].r.esp = 0x4000000;
    execute_in_usermode(queue[last++]);
}
