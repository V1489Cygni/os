#include "irq.h"

#include "idt.h"
#include "service.h"

void *irq_routines[16] = {
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0
};

void irq_install_handler(int irq, void (*handler)(regs *r)) {
    irq_routines[irq] = handler;
}

void irq_uninstall_handler(int irq) {
    irq_routines[irq] = 0;
}

void irq_remap() {
    outportb(0x20, 0x11);
    outportb(0xA0, 0x11);
    outportb(0x21, 0x20);
    outportb(0xA1, 0x28);
    outportb(0x21, 0x04);
    outportb(0xA1, 0x02);
    outportb(0x21, 0x01);
    outportb(0xA1, 0x01);
    outportb(0x21, 0x0);
    outportb(0xA1, 0x0);
}

void init_irq() {
    irq_remap();
    set_idt_entry(32, (unsigned)irq0, 0x08, 0x8E);
    set_idt_entry(33, (unsigned)irq1, 0x08, 0x8E);
    set_idt_entry(34, (unsigned)irq2, 0x08, 0x8E);
    set_idt_entry(35, (unsigned)irq3, 0x08, 0x8E);
    set_idt_entry(36, (unsigned)irq4, 0x08, 0x8E);
    set_idt_entry(37, (unsigned)irq5, 0x08, 0x8E);
    set_idt_entry(38, (unsigned)irq6, 0x08, 0x8E);
    set_idt_entry(39, (unsigned)irq7, 0x08, 0x8E);
    set_idt_entry(40, (unsigned)irq8, 0x08, 0x8E);
    set_idt_entry(41, (unsigned)irq9, 0x08, 0x8E);
    set_idt_entry(42, (unsigned)irq10, 0x08, 0x8E);
    set_idt_entry(43, (unsigned)irq11, 0x08, 0x8E);
    set_idt_entry(44, (unsigned)irq12, 0x08, 0x8E);
    set_idt_entry(45, (unsigned)irq13, 0x08, 0x8E);
    set_idt_entry(46, (unsigned)irq14, 0x08, 0x8E);    
    set_idt_entry(47, (unsigned)irq15, 0x08, 0x8E);
}

void irq_handler(regs *r) {
    void (*handler)(regs *r);
    handler = irq_routines[r->int_no - 32];
    if (handler) {
        handler(r);
    }
    if (r->int_no >= 40) {
        outportb(0xA0, 0x20);
    }
    outportb(0x20, 0x20);
}