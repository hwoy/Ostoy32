include ../../Makefile.in
include ../../Makefile.lib.in

CFLAGS += -D_SYSCALL_

listo = get_driveno.o

LIBNAME =libboot.a

.PHONY: all clean install update

all:	$(LIBNAME) 
$(LIBNAME):	$(listo)
	$(AR) -rc $(LIBNAME)  $(listo)

install: all
		cp *.a ../

update:
		$(MAKE) clean && $(MAKE) install

clean:	
	rm -f *.o *.a *~ 

make-dep:
	$(CC) -MM $(CFLAGS) *.c


get_driveno.o: get_driveno.c ../../include/stdint.h ../../include/boot.h
