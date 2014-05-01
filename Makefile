CC=gcc
AS=yasm
LD=ld

CFLAGS=-m32 -fno-stack-protector -fno-builtin -nostdinc -std=c99
ASFLAGS=-f elf32
LDFLAGS=-melf_i386 -T link.ld

CSOURCES=k0/main.c k0/output.c k0/service.c k0/gdt.c k0/idt.c k0/isr.c k0/irq.c\
k1/main.c k1/input.c k1/syscalls.c k1/syscalls/get_char_tty.c k1/syscalls/print_tty.c\
init/init.c init/shell.c k1/memory/paging.c k1/memory/physical.c k1/pit.c k1/scheduler.c
ASMSOURCES=./k0/loader.asm ./k0/gdt.asm ./k0/idt.asm ./k0/isr.asm ./k0/irq.asm ./k1/syscalls.asm\
./include/syscalls.asm ./k1/memory/paging.asm ./k1/scheduler.asm

COBJECTS=$(CSOURCES:.c=.o)
ASMOBJECTS=$(ASMSOURCES:.asm=_asm.o)

OUTPUT=kernel.bin
ISO=image.iso

run: iso
	qemu-system-i386 $(ISO) -s

iso: all
	mkdir -p temp
	mkdir -p temp/boot
	cp kernel.bin temp/boot/kernel.bin
	mkdir -p temp/boot/grub
	cp ./grub/grub.cfg temp/boot/grub/grub.cfg
	grub-mkrescue -o $(ISO) temp
	rm -rf temp

all: $(ASMOBJECTS) $(COBJECTS)
	$(LD) $(LDFLAGS) -o $(OUTPUT) $(ASMOBJECTS) $(COBJECTS)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

%_asm.o: %.asm
	$(AS) $(ASFLAGS) $< -o $@

clean:
	rm -f $(OUTPUT) $(ISO) $(COBJECTS) $(ASMOBJECTS)

