include ../../Makefile.in
include ../../Makefile.lib.in

LIBNAME =libasm.a

.PHONY: all clean install update obj

all:	$(LIBNAME) 
$(LIBNAME):	asm.o
	$(AR) -rc $(LIBNAME)  asm.o
	
asm.o: asm.s
	$(AS) -o asm.o asm.s

install: all
		cp *.a ../

update:
		$(MAKE) clean && $(MAKE) install

clean:	
	rm -f *.o *.a *~ 
