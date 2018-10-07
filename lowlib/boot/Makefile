include ../../Makefile.in
include ../../Makefile.lib.in

CFLAGS += -D_SYSCALL_

listc = get_driveno.c
listo = get_driveno.o
LIBNAME =libboot.a

.PHONY: all clean install update

all:	$(LIBNAME) 
$(LIBNAME):	$(listo)
	$(AR) -rc $(LIBNAME)  $(listo)

$(listo): $(listc)
	$(CC) -c $(CFLAGS)    $(listc)
	
get_char.s: get_char.c
	$(CC) -S $(CFLAGS) get_char.c

install: all
		cp *.a ../

update:
		$(MAKE) clean && $(MAKE) install

clean:	
	rm -f *.o *.a *~ 
