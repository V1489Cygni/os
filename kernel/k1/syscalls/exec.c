#include <syscalls.h>
#include <scheduler.h>

void exec(regs* r) {
    start_task(r->ecx);
}
