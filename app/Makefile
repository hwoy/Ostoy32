include ../Makefile.in

LIB=-lconio -lc -lcpuid -lOstoy32

INCLUDEDIR = -I../include

ASFLAGS=-I../include

LDFLAGS = -L../lib -L../lowlib -nostdlib

CFLAGS += $(INCLUDEDIR)


.PHONY: all clean

all:	app

app:	app2.o
	$(LD) $(LDFLAGS) -e start -N -Ttext 0x400000 -o app app2.o --oformat binary

app2.o:	app2.s app.bin
	$(AS) $(ASFLAGS) -o app2.o app2.s

app.bin:	main.o slider.o sliderio.o lcg.o minstd.o
	$(LD) $(LDFLAGS) -Map=app.map -e main -N -Ttext 0x400000 --oformat binary $(LDFLAGS) -o app.bin main.o slider.o sliderio.o lcg.o minstd.o $(LIB)


main.o: main.c slider.h sliderio.h
slider.o: slider.c slider.h
sliderio.o: sliderio.c sliderio.h slider.h
lcg.o: lcg.c lcg.h
minstd.o: minstd.c minstd.h lcg.h

clean:	
	rm -f *.o *.map app app.bin  *~  app.s str.h
	
