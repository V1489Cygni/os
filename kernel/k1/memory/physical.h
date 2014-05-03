#ifndef MEMORY_PHYSICAL_H
#define MEMORY_PHYSICAL_H

void set_used(void*);
void set_unused(void*);
char get_state(void*);
void init_physical();

#endif
