include ../Makefile.in

LIB=-lc -lOstoy32

INCLUDEDIR = -I../include

ASFLAGS=-I../kernel32/include

LDFLAGS = -L../lib -nostdlib

CXXFLAGS += $(INCLUDEDIR)


.PHONY: all clean

all:	app

app:	app2.o
	$(LD) $(LDFLAGS) -e start -N -Ttext 0x400000 -o app app2.o --oformat binary

app2.o:	app2.s app.bin
	$(AS) $(ASFLAGS) -o app2.o app2.s

app.bin:	main.o
	$(LD) $(LDFLAGS) -Map=app.map -e main -N -Ttext 0x400000 --oformat binary $(LDFLAGS) -o app.bin main.o $(LIB)


clean:	
	rm -f *.o *.map app app.bin  *~  app.s str.h
	
main.o: main.cpp ../include/cstdio ../include/stdio.h
