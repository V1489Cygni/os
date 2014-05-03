#include <syscalls.h>

void init_main() {
    sc_print("Hello!");
    for(;;) {}
}
