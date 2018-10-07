include ../../Makefile.in
LIBDIR = ../../lib
INCLUDEDIR = -I../../include

LDFLAGS = -L$(LIBDIR) -nostdlib

CFLAGS += $(INCLUDEDIR)


.PHONY: all clean

all:	timer.o


timer.o: timer.c
	$(CC) -c $(CFLAGS) timer.c

clean:
	rm -f *.o ~*
