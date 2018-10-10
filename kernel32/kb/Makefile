include ../../Makefile.in

LIBDIR = -L../lib -L../drivers
INCLUDEDIR = -I../include  -I../../include

LDFLAGS = $(LIBDIR) -nostdlib

CFLAGS += $(INCLUDEDIR)


.PHONY: all clean

all:	kb.o

kb.o: kb.c
	$(CC) -c $(CFLAGS) kb.c
clean:
	rm -f *.o ~*
