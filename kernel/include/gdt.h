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

typedef struct {
    int prev_tss;
    int esp0;
    int ss0;
    int esp1;
    int ss1;
    int esp2;
    int ss2;
    int cr3;
    int eip;
    int eflags;
    int eax;
    int ecx;
    int edx;
    int ebx;
    int esp;
    int ebp;
    int esi;
    int edi;
    int es;
    int cs;
    int ss;
    int ds;
    int fs;
    int gs;
    int ldt;
    int trap;
    int iomap_base;
}__attribute__((packed)) tss_entry;

extern void load_gdt();
extern void load_tss();

void set_gdt_entry(int, int, int, unsigned char, unsigned char);
void init_gdt();
void init_tss();

#endif
