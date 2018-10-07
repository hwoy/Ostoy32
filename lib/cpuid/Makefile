include ../../Makefile.in
include ../../Makefile.lib.in

listc = cpuid.c  getcpuextstr.c  getcpustr.c
listo = cpuid.o  getcpuextstr.o  getcpustr.o
LIBNAME =libcpuid.a

.PHONY: all clean install update obj

all:	$(LIBNAME)
$(LIBNAME):	obj
	$(AR) -rc $(LIBNAME)  $(listo)

obj: $(listc)
	$(CC) -c $(CFLAGS)    $(listc)
	


install: all
		cp *.a ../
	
update:
		$(MAKE) clean && $(MAKE) install

clean:	
	rm -f *.o *.a *~ 
