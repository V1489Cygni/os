#ifndef INCLUDE_SYSCALLS_H
#define INCLUDE_SYSCALLS_H

static void sc_get_char(char* c) {
    __asm__ __volatile__ ("mov $0, %eax");
    __asm__ __volatile__ ("mov 0x8(%esp), %ecx");
    __asm__ __volatile__ ("int $0x80");
}

static void sc_print(char* c) {
    __asm__ __volatile__ ("mov $1, %eax");
    __asm__ __volatile__ ("mov 0x8(%esp), %ecx");
    __asm__ __volatile__ ("int $0x80");
}

static void exec(void* a) {
    __asm__ __volatile__ ("mov $2, %eax");
    __asm__ __volatile__ ("mov 0x8(%esp), %ecx");
    __asm__ __volatile__ ("int $0x80");
}

#endif
