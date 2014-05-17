#include <idt.h>
#include <service.h>

idt_entry idt[256];
idt_ptr idtp;

void set_idt_entry(unsigned char num, unsigned long base, unsigned short sel, unsigned char flags) {
    idt[num].base_lo = (base & 0xFFFF);
    idt[num].base_hi = (base >> 16) & 0xFFFF;
    idt[num].sel = sel;
    idt[num].always0 = 0;
    idt[num].flags = flags;
}

void init_idt() {
    idtp.limit = (sizeof (idt_entry) * 256) - 1;
    idtp.base = (int)&idt;
    memset((char*)&idt, 0, sizeof(idt_entry) * 256);
    load_idt();
}
