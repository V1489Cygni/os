#include "../k1/input.h"
#include "../k0/output.h"

#define BUFFER_SIZE 256

char buffer[BUFFER_SIZE];

void get_line() {
    int now = 0;
    for(;;) {
        char c = get_char();
        if(c == 0x0e) {
            if(now > 0) {
                now--;
                k0_print_char(0x08);
            }
        } else if(c == 0x1c) {
            buffer[now] = '\0';
            k0_print_char('\n');
            return;
        } else {
            buffer[now++] = c;
            k0_print_char(c);
        }
    }
}

int shell_main() {
    for(;;) {
        k0_print("> ");
        get_line();
        k0_print("Unknown command!\n");
    }
    return 0;
}
