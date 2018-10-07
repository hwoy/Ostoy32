include ../Makefile.in

BIN=kernel32

INCLUDEDIR = -I../include -Iinclude

ASFLAGS=$(INCLUDEDIR)

LDFLAGS = -L../lib -L../lowlib -Llib -Llib/kprintf -nostdlib


INITIP = init.c pic_install.c idt_install.c isr_entry.c

LIB=-lkpf -lc -lconio -lvga -lkb -lboot -ltimer

.PHONY: all clean lib

all:	$(BIN)

$(BIN): setup32 init32
	cat setup32 init32 > $(BIN)

init32: init32.o
	$(LD) $(LDFLAGS)  -e _start -N -Ttext 0x300000 --oformat binary -o init32 init32.o
init32.o: init32.s init32.bin
	$(AS) $(ASFLAGS)  -o init32.o init32.s
init32.bin: init/init.o isr/isr.a kb/kb.o timer/timer.o syscall/syscall.a lib
	$(LD) $(LDFLAGS) -Map=init32.bin.map  -e init -N -Ttext 0x300000 --oformat binary -o init32.bin init/init.o isr/isr.a kb/kb.o timer/timer.o syscall/syscall.a $(LIB)

setup32:	setup32.o
	$(LD) $(LDFLAGS) -Map=setup32_img.map -e _start -N -Ttext 0x7c00 --oformat binary -o setup32 setup32.o



setup32.o:	setup32.s
	$(AS) $(ASFLAGS)  -o setup32.o setup32.s


init/init.o:
	$(MAKE) -C init
isr/isr.a:
	$(MAKE) -C isr
kb/kb.o:
	$(MAKE) -C kb
timer/timer.o:
	$(MAKE) -C timer
syscall/syscall.a:
	$(MAKE) -C syscall
lib:
	$(MAKE) -C lib
clean:
	rm -f  $(BIN) setup32  *.o $ *.map *~ init32 *.bin && \
$(MAKE) -C init clean && $(MAKE) -C isr clean && $(MAKE) -C kb clean && $(MAKE) -C timer clean && $(MAKE) -C syscall clean && $(MAKE) -C lib clean



