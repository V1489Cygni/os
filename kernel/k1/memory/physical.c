#include <physical.h>

char map[131072];

void set_used(void* addr) {
    int number = (int)addr / 4096;
    int byte_num = number / 8;
    int offset = number % 8;
    map[byte_num] |= (1 << offset);
}

void set_unused(void* addr) {
    int number = (int)addr / 4096;
    int byte_num = number / 8;
    int offset = number % 8;
    map[byte_num] &= (0xff ^ (1 << offset));
}

char get_state(void* addr) {
    int number = (int)addr / 4096;
    int byte_num = number / 8;
    int offset = number % 8;
    return map[byte_num] & (1 << offset);
}

void init_physical() {
    for(int i = 0; i < 4096; i++) {
        set_used((void*) (i * 4096));
    }
}
