include ../../Makefile.in

LIBDIR = -L../lib -L../drivers
INCLUDEDIR = -I../include

LDFLAGS = $(LIBDIR) -nostdlib

CFLAGS += $(INCLUDEDIR)


.PHONY: all clean

all:	isr.a

isr.a: isr.o exception.o
	$(AR) -rc isr.a isr.o exception.o

isr.o: isr.s
	$(AS) -o isr.o isr.s
exception.o: exception.c
	$(CC) -c $(CFLAGS) exception.c
clean:
	rm -f isr.a isr.o exception.o ~*
