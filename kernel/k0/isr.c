#include <isr.h>
#include <idt.h>
#include <output.h>

char *exception_messages[] = {
    (char*)"Division By Zero",
    (char*)"Debug",
    (char*)"Non Maskable Interrupt",
    (char*)"Breakpoint",
    (char*)"Into Detected Overflow",
    (char*)"Out of Bounds",
    (char*)"Invalid Opcode",
    (char*)"No Coprocessor",
    (char*)"Double Fault",
    (char*)"Coprocessor Segment Overrun",
    (char*)"Bad TSS",
    (char*)"Segment Not Present",
    (char*)"Stack Fault",
    (char*)"General Protection Fault",
    (char*)"Page Fault",
    (char*)"Unknown Interrupt",
    (char*)"Coprocessor Fault",
    (char*)"Alignment Check",
    (char*)"Machine Check",
    (char*)"Reserved",
    (char*)"Reserved",
    (char*)"Reserved",
    (char*)"Reserved",
    (char*)"Reserved",
    (char*)"Reserved",
    (char*)"Reserved",
    (char*)"Reserved",
    (char*)"Reserved",
    (char*)"Reserved",
    (char*)"Reserved",
    (char*)"Reserved",
    (char*)"Reserved"
};

void init_isr() {
    set_idt_entry(0, (unsigned)isr0, 0x08, 0x8E);
    set_idt_entry(1, (unsigned)isr1, 0x08, 0x8E);
    set_idt_entry(2, (unsigned)isr2, 0x08, 0x8E);
    set_idt_entry(3, (unsigned)isr3, 0x08, 0x8E);
    set_idt_entry(4, (unsigned)isr4, 0x08, 0x8E);
    set_idt_entry(5, (unsigned)isr5, 0x08, 0x8E);
    set_idt_entry(6, (unsigned)isr6, 0x08, 0x8E);
    set_idt_entry(7, (unsigned)isr7, 0x08, 0x8E);
    set_idt_entry(8, (unsigned)isr8, 0x08, 0x8E);
    set_idt_entry(9, (unsigned)isr9, 0x08, 0x8E);
    set_idt_entry(10, (unsigned)isr10, 0x08, 0x8E);
    set_idt_entry(11, (unsigned)isr11, 0x08, 0x8E);
    set_idt_entry(12, (unsigned)isr12, 0x08, 0x8E);
    set_idt_entry(13, (unsigned)isr13, 0x08, 0x8E);
    set_idt_entry(14, (unsigned)isr14, 0x08, 0x8E);
    set_idt_entry(15, (unsigned)isr15, 0x08, 0x8E);
    set_idt_entry(16, (unsigned)isr16, 0x08, 0x8E);
    set_idt_entry(17, (unsigned)isr17, 0x08, 0x8E);
    set_idt_entry(18, (unsigned)isr18, 0x08, 0x8E);
    set_idt_entry(19, (unsigned)isr19, 0x08, 0x8E);
    set_idt_entry(20, (unsigned)isr20, 0x08, 0x8E);
    set_idt_entry(21, (unsigned)isr21, 0x08, 0x8E);
    set_idt_entry(22, (unsigned)isr22, 0x08, 0x8E);
    set_idt_entry(23, (unsigned)isr23, 0x08, 0x8E);
    set_idt_entry(24, (unsigned)isr24, 0x08, 0x8E);
    set_idt_entry(25, (unsigned)isr25, 0x08, 0x8E);
    set_idt_entry(26, (unsigned)isr26, 0x08, 0x8E);
    set_idt_entry(27, (unsigned)isr27, 0x08, 0x8E);
    set_idt_entry(28, (unsigned)isr28, 0x08, 0x8E);
    set_idt_entry(29, (unsigned)isr29, 0x08, 0x8E);
    set_idt_entry(30, (unsigned)isr30, 0x08, 0x8E);
    set_idt_entry(31, (unsigned)isr31, 0x08, 0x8E);
}

void isr_handler(regs *r) {
    if (r->int_no < 32) {
        k0_print(exception_messages[r->int_no]);
        k0_print((char*)" Exception. System Halted!\n");
        __asm__ __volatile__ ("cli");
        __asm__ __volatile__ ("hlt");
    }
}
