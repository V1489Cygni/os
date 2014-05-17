#include <service.h>

void memcpy(char *dest, const char *src, int count) {
    for (int i = 0; i < count; i++) {
        dest[i] = src[i];
    }
}

void memset(char *dest, char val, int count) {
    for (int i = 0; i < count; i++) {
        dest[i] = val;
    }
}

void memsetw(short *dest, short val, int count) {
    for (int i = 0; i < count; i++) {
        dest[i] = val;
    }
}

void memsetd(int *dest, int val, int count) {
    for (int i = 0; i < count; i++) {
        dest[i] = val;
    }
}

int strlen(const char *str) {
    for (int i = 0;; i++) {
        if (str[i] == '\0') {
            return i;
        }
    }
}

unsigned char inportb (unsigned short port) {
    unsigned char result;
    __asm__ __volatile__ ("inb %1, %0" : "=a" (result) : "dN" (port));
    return result;
}

void outportb (unsigned short port, unsigned char data) {
    __asm__ __volatile__ ("outb %1, %0" : : "dN" (port), "a" (data));
}
