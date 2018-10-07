cc = gcc -m32
as = as --32
ar = ar
link = ld -m elf_i386

libdir =-L../../lib -L../../lowlib

includedir =../../include

LDFLAGS = $(libdir) -nostdlib

CFLAGS =-Wall -pedantic -W -nostdlib -nostdinc -Wno-long-long  -fomit-frame-pointer -fno-asynchronous-unwind-tables -fno-builtin -I$(includedir)

listc = putnum.c putnumbin.c putnumhex.c parsenum.c
listo = putnum.o putnumbin.o putnumhex.o parsenum.o
libname =libputnum.a

.PHONY: all clean install update obj

all:	$(libname)
$(libname):	obj
	$(ar) -rc $(libname)  $(listo)

obj: $(listc)
	$(cc) -c $(CFLAGS)   $(listc)
	


install:
	make
update:
		make clean && make install

clean:	
	rm -f *.o *.a *~ 
