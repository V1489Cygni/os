#include <gdt.h>
#include <service.h>
#include <output.h>

#define ENTRY_NUMBER 6

gdt_entry gdt[ENTRY_NUMBER];
gdt_ptr gp;

void set_gdt_entry(int num, int base, int limit, unsigned char access, unsigned char gran) {
    gdt[num].base_low = (base & 0xFFFF);
    gdt[num].base_middle = (base >> 16) & 0xFF;
    gdt[num].base_high = (base >> 24) & 0xFF;
    gdt[num].limit_low = (limit & 0xFFFF);
    gdt[num].granularity = ((limit >> 16) & 0x0F);
    gdt[num].granularity |= (gran & 0xF0);
    gdt[num].access = access;
}

tss_entry tss;

void init_tss(int num, int ss0, int esp0) {
    set_gdt_entry(num, (int)&tss, (int)(&tss + sizeof(tss_entry)), 0xE9, 4);
    memset((char*)&tss, 0, sizeof(tss));
    tss.ss0 = ss0;// * 65536;
    tss.esp0 = esp0;
    tss.cs = 0xB;
    tss.es = tss.ds = tss.ss = tss.fs = tss.gs = 0x13;
}

void set_esp(int esp) {
    tss.esp0 = esp;
}

void init_gdt() {
    gp.limit = (sizeof(gdt_entry) * ENTRY_NUMBER) - 1;
    gp.base = (int)&gdt;
    set_gdt_entry(0, 0, 0, 0, 0);
    set_gdt_entry(1, 0, 0xFFFFFFFF, 0x9A, 0xCF);
    set_gdt_entry(2, 0, 0xFFFFFFFF, 0x92, 0xCF);
    set_gdt_entry(3, 0, 0xFFFFFFFF, 0xFA, 0xCF);
    set_gdt_entry(4, 0, 0xFFFFFFFF, 0xF2, 0xCF);
    init_tss(5, 0x10, 0x20000000);
    load_gdt();
    load_tss();
}
