#include "output.h"
#include "gdt.h"
#include "idt.h"
#include "isr.h"
#include "irq.h"

extern int k1_main();

int k0_main() {
    k0_cls();
    k0_print("Kernel level 0 loaded.\nInitializing GDT... ");
    init_gdt();
    k0_print("OK\nInitializing IDT... ");
    init_idt();
    k0_print("OK\nInitializing ISR... ");
    init_isr();
    k0_print("OK\nInitializing IRQ... ");
    init_irq();
    k0_print("OK\n");
    k1_main();
    return 0;
}
