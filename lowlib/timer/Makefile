include ../../Makefile.in
include ../../Makefile.lib.in

CFLAGS += -D_SYSCALL_


listo = delay.o get_timetick.o

LIBNAME =libtimer.a

.PHONY: all clean install update make-dep

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
	$(MAKE) -MM $(CFLAGS) *.c

delay.o: delay.c ../../include/timer.h
get_timetick.o: get_timetick.c ../../include/timer.h
