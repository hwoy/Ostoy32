include ../../Makefile.in

LIBDIR = ../../lib
INCLUDEDIR = ../../include

LDFLAGS = -L$(LIBDIR) -nostdlib

CFLAGS += -I$(INCLUDEDIR)


.PHONY: all clean

all:	kb.o

kb.o: kb.c
	$(CC) -c $(CFLAGS) kb.c
clean:
	rm -f *.o ~*
