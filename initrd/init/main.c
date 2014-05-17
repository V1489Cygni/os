#include <syscalls.h>

//extern void shell_main();

void init_main() {
    sc_print("Hello!\n");
    shell_main();
    //__asm__ __volatile__ ("hlt");
    for(;;) {}
}
