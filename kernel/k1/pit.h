#ifndef K1_PIT_H
#define K1_PIT_H

#include "../k0/regs.h"

void timer_phese();
void timer_handler(regs*);
void init_pit();

#endif
