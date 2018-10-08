include ../../Makefile.in
include ../../Makefile.lib.in

listo = cpuid.o  getcpuextstr.o  getcpustr.o

LIBNAME =libcpuid.a

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
	$(CC) -MM $(CFLAGS) *.c

cpuid.o: cpuid.c ../../include/cpuid.h
getcpuextstr.o: getcpuextstr.c ../../include/cpuid.h
getcpustr.o: getcpustr.c ../../include/cpuid.h
