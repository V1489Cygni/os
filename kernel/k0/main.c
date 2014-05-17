#include <output.h>
#include <gdt.h>
#include <idt.h>
#include <isr.h>
#include <irq.h>
#include <multiboot.h>

extern int k1_main(module_header_t *);

int k0_main(multiboot_header_t *header) {
    k0_cls();
    module_header_t *mod_header = (module_header_t *)header->mods_addr;
    //msg[4] = '\0';
    //k0_print(msg);
    //k0_print_char('\n');
    k0_print("Kernel level 0 loaded.\nInitializing GDT... ");
    init_gdt();
    k0_print("OK\nInitializing IDT... ");
    init_idt();
    k0_print("OK\nInitializing ISR... ");
    init_isr();
    k0_print("OK\nInitializing IRQ... ");
    init_irq();
    k0_print("OK\n");
    k1_main(mod_header);
    return 0;
}
