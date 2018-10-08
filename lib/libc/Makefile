include ../../Makefile.in
include ../../Makefile.lib.in

listc = memchr.c memset.c memcmp.c memcpy.c  smemset.c  strchr.c strcmp.c  strlen.c  strcpy.c strncmp.c puts.c putchar.c printf.c abs.c toupper.c tolower.c atoi.c strtol.c gets.c getchar.c rand.c srand.c
listo = memchr.o memset.o memcmp.o memcpy.o  smemset.o  strchr.o strcmp.o  strlen.o  strcpy.o strncmp.o puts.o putchar.o printf.o abs.o toupper.o tolower.o atoi.o strtol.o gets.o getchar.o rand.o srand.o
LIBNAME =libc.a

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
