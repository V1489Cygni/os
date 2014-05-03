#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "../k0/regs.h"

typedef struct {
    regs r;
} proc_info;

void execute_in_usermode(proc_info);

void start_task(int);

#endif
