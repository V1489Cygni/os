#include "../k0/output.h"
#include "input.h"

extern int init_main();

int k1_main() {
    k0_print("Kernel level 1 loaded.\nInitializing keyboard... ");
    init_keyboard();
    k0_print("OK\nEnableing interupts... ");
    __asm__ __volatile__ ("sti");
    k0_print("OK\n");
    init_main();
    return 0;
}
