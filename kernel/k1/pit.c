#include <pit.h>
#include <service.h>
#include <irq.h>
#include <regs.h>
#include <output.h>

int timer_ticks = 0;

void timer_phase(int hz) {
    int divisor = 1193180 / hz;
    outportb(0x43, 0x36);
    outportb(0x40, divisor & 0xFF);
    outportb(0x40, divisor >> 8);
}

void timer_handler(regs *r) {
    timer_ticks++;
    if (timer_ticks % 18 == 0) {
        //k0_print("One second has passed\n");
    }
}

void init_pit() {
    irq_install_handler(0, timer_handler);
}
