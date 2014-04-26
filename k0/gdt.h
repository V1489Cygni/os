#ifndef K0_GDT_H
#define K0_GDT_H

typedef struct {
    unsigned short limit_low;
    unsigned short base_low;
    unsigned char base_middle;
    unsigned char access;
    unsigned char granularity;
    unsigned char base_high;
}__attribute__((packed)) gdt_entry;

typedef struct {
    unsigned short limit;
    unsigned int base;
}__attribute__((packed)) gdt_ptr;

extern void load_gdt();
void set_gdt_entry(int, unsigned long, unsigned long, unsigned char, unsigned char);
void init_gdt();

#endif
