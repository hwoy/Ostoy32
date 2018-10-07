include ../../Makefile.in
LIBNAME=init

LIBDIR = ../../LIBNAME
INCLUDEDIR = ../../include

LDFLAGS = -L$(LIBDIR) -nostdLIBNAME

CFLAGS += -I$(INCLUDEDIR)

.PHONY: all clean

all:$(LIBNAME).o

$(LIBNAME).o: init.c
	$(CC) -c  $(CFLAGS) init.c

clean:
	rm -f *.o *~


