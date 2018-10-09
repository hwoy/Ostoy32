include ../../Makefile.in

LIBDIR = -L../lib -L../drivers
INCLUDEDIR = -I../include

LDFLAGS = $(LIBDIR) -nostdlib

CFLAGS += $(INCLUDEDIR)


.PHONY: all clean

all:	timer.o


timer.o: timer.c
	$(CC) -c $(CFLAGS) timer.c

clean:
	rm -f *.o ~*
