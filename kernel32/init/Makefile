include ../../Makefile.in
LIBNAME=init

LIBDIR = -L../lib -L../drivers
INCLUDEDIR = -I../include

LDFLAGS = $(LIBDIR) -nostdLIBNAME

CFLAGS += $(INCLUDEDIR)

.PHONY: all clean

all:$(LIBNAME).o

$(LIBNAME).o: init.c
	$(CC) -c  $(CFLAGS) init.c

clean:
	rm -f *.o *~


