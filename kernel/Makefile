CC=gcc
AS=yasm
LD=ld

CFLAGS=-m32 -fno-stack-protector -fno-builtin -nostdinc -std=c99 -I include
ASFLAGS=-f elf32
LDFLAGS=-melf_i386 -T link.ld

CSOURCES=k0/main.c k0/output.c k0/service.c k0/gdt.c k0/idt.c k0/isr.c k0/irq.c\
k1/main.c k1/input.c k1/syscalls.c k1/syscalls/get_char_tty.c k1/syscalls/print_tty.c k1/syscalls/exec.c\
k1/memory/paging.c k1/memory/physical.c k1/pit.c k1/scheduler.c
ASMSOURCES=k0/loader.asm k0/gdt.asm k0/idt.asm k0/isr.asm k0/irq.asm k1/syscalls.asm\
k1/memory/paging.asm k1/scheduler.asm

COBJECTS=$(CSOURCES:.c=.o)
ASMOBJECTS=$(ASMSOURCES:.asm=_asm.o)

OUTPUT=kernel.bin

all: $(ASMOBJECTS) $(COBJECTS)
	$(LD) $(LDFLAGS) -o $(OUTPUT) $(ASMOBJECTS) $(COBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%_asm.o: %.asm
	$(AS) $(ASFLAGS) $< -o $@

clean:
	rm -f $(OUTPUT) $(ASMOBJECTS) $(COBJECTS)

