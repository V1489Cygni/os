CC=gcc
AS=yasm
LD=ld

CFLAGS=-m32 -fno-stack-protector -fno-builtin -nostdinc -g -O -Wall -I. -std=c99
ASFLAGS=-f elf32
LDFLAGS=-melf_i386 -T link.ld

CSOURCES=./k0/main.c ./k0/output.c ./k0/service.c ./k0/gdt.c ./k0/idt.c ./k0/isr.c ./k0/irq.c\
./k1/main.c ./k1/input.c ./init/init.c ./init/shell.c
ASMSOURCES=./k0/loader.asm ./k0/gdt.asm ./k0/idt.asm ./k0/isr.asm ./k0/irq.asm

COBJECTS=$(CSOURCES:.c=.o)
ASMOBJECTS=$(ASMSOURCES:.asm=_asm.o)

OUTPUT=kernel.bin
ISO=image.iso

run: iso
	qemu-system-i386 $(ISO)

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
