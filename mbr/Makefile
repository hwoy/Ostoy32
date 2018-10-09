include ../Makefile.in

ASFLAGS=-I"../include" -I../kernel32/include

.PHONY: all clean

all:	mbr
mbr: mbr.o
	$(LD)  -N -e _start -Ttext 0x7c00 --oformat binary  -o mbr mbr.o



mbr.o:	mbr.s
	$(AS) $(ASFLAGS) -o mbr.o mbr.s
clean:
	rm -f *.o mbr *~
	
