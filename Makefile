ISO=image.iso
KERNEL=kernel/kernel.bin
INITRD=initrd/initrd

run: iso
	qemu-system-i386 $(ISO) -s

iso: kernel initrd
	mkdir -p temp
	mkdir -p temp/boot
	cp $(KERNEL) temp/boot/kernel.bin
	cp $(INITRD) temp/boot/initrd
	mkdir -p temp/boot/grub
	cp grub.cfg temp/boot/grub/grub.cfg
	grub-mkrescue -o $(ISO) temp
	rm -rf temp

.PHONY: kernel

kernel:
	$(MAKE) -C kernel

.PHONY: initrd

initrd:
	$(MAKE) -C initrd

clean:
	$(MAKE) -C kernel clean
	$(MAKE) -C initrd clean
	rm -f $(ISO)
