CC=gcc
AS=yasm
LD=ld

CFLAGS=-m32 -fno-stack-protector -fno-builtin -nostdinc -std=c99 -I include
ASFLAGS=-f elf32
LDFLAGS=-melf_i386 -T link.ld

CSOURCES=init/main.c utils/shell.c
ASMSOURCES=init/loader.asm

COBJECTS=$(CSOURCES:.c=.o)
ASMOBJECTS=$(ASMSOURCES:.asm=_asm.o)

OUTPUT=initrd

all: $(ASMOBJECTS) $(COBJECTS)
	$(LD) $(LDFLAGS) -o $(OUTPUT) $(ASMOBJECTS) $(COBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%_asm.o: %.asm
	$(AS) $(ASFLAGS) $< -o $@

clean:
	rm -f $(OUTPUT) $(ASMOBJECTS) $(COBJECTS)
