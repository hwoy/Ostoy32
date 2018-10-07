include ../../Makefile.in
include ../../Makefile.lib.in

CFLAGS += -D_SYSCALL_

listc = delay.c get_timetick.c
listo = delay.o get_timetick.o
LIBNAME =libtimer.a

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
