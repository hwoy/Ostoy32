include ../../Makefile.in
LIB=syscall

LIBDIR = -L../lib -L../drivers
INCLUDEDIR = -I../include

LDFLAGS = $(LIBDIR) -nostdlib
ASFLAGS = $(INCLUDEDIR)

CFLAGS += $(INCLUDEDIR)

.PHONY: all clean

all: $(LIB).a

$(LIB).a: syscall.o syscall_isr.o
	$(AR) -rc $(LIB).a syscall.o syscall_isr.o
syscall.o: syscall.c
	$(CC) -c  $(CFLAGS) syscall.c
syscall_isr.o: syscall_isr.s
	$(AS) $(ASFLAGS) -o syscall_isr.o syscall_isr.s
clean:
	rm -f *.o *~ *.a


