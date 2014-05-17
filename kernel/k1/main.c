#include <output.h>
#include <input.h>
#include <syscalls.h>
#include <paging.h>
#include <physical.h>
#include <pit.h>
#include <scheduler.h>
#include <multiboot.h>
#include <service.h>

int k1_main(module_header_t *initrd_header) {
    k0_print("Kernel level 1 loaded.\nInitializing keyboard... ");
    init_keyboard();
    k0_print("OK\nInitializing syscalls... ");
    init_syscalls();
    k0_print("OK\nInitializing memory management... ");
    init_physical();
    k0_print("OK\nInitializing paging... ");
    //init_paging();
    k0_print("OK\nInitializing timer... ");
    init_pit();
    k0_print("OK\nEnableing interupts... ");
    __asm__ __volatile__ ("sti");
    k0_print("OK\n");
    int size = initrd_header->mod_end - initrd_header->mod_start;
    int *module = (int *)initrd_header->mod_start;
    for(int i = 0; i < size / 4; i++) {
        if(module[i] == 0xC0DEAA55) {
            k0_print("Found.\n");
            memcpy((char *)0x1000000, (char *)module + 4 * i, size);
            start_task(0x1000004);
        }
    }
    return 0;
}
