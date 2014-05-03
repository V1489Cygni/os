#include "../include/syscalls.h"
#include "../k0/output.h"

#define BUFFER_SIZE 256

char buffer[BUFFER_SIZE];

void get_line() {
    int now = 0;
    char c[2];
    c[1] = '\0';
    for(;;) {
        sc_get_char(&c[0]);
        if(c[0] == 0x0e) {
            if(now > 0) {
                now--;
                c[0] = 0x08;
                sc_print(&c[0]);
            }
        } else if(c[0] == 0x1c) {
            buffer[now] = '\0';
            c[0] = '\n';
            sc_print(&c[0]);
            return;
        } else {
            buffer[now++] = c[0];
            sc_print(&c[0]);
        }
    }
}

int shell_main() {
    for(;;) {
        sc_print("> ");
        get_line();
        if(buffer[0] == 'f' && buffer[1] == '\0') {
            __asm__ __volatile__ ("hlt");
        }
        sc_print("Unknown command!\n");
    }
    return 0;
}
