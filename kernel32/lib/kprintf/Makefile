include ../../../Makefile.in

LIBDIR = -L../../drivers

INCLUDEDIR = -I../../include -I../../../include

LDFLAGS = $(LIBDIR) -nostdlib

CFLAGS += $(INCLUDEDIR)

listc = kprintf.c  kputchar.c
listo = kprintf.o  kputchar.o

LIBNAME =libkpf.a

.PHONY: all clean install update

all:	$(LIBNAME) 
$(LIBNAME):	$(listo)
	$(AR) -rc $(LIBNAME)  $(listo)

$(listo): $(listc)
	$(CC) -c $(CFLAGS)    $(listc)
	
scall.s:
	$(CC) -S $(CFLAGS)    $(listc)

install: all
	cp *.a ../

update:
		$(MAKE) clean && $(MAKE) install

clean:	
	rm -f *.o *.a *~ 
