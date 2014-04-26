#ifndef K1_INPUT_H
#define K1_INPUT_H

#include "../k0/regs.h"

void keyboard_handler(regs*);
char get_char();
void init_keyboard();

#endif
