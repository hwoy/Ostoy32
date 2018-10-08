include ../../Makefile.in
include ../../Makefile.lib.in


LIBNAME =libc.a

.PHONY: all clean install update make-dep

listo = abs.o atoi.o getchar.o gets.o memchr.o memcmp.o memcpy.o memset.o printf.o \
putchar.o puts.o rand.o smemset.o srand.o strchr.o strcmp.o strcpy.o strlen.o strncmp.o \
strtol.o tolower.o toupper.o 

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

abs.o: abs.c ../../include/stdlib.h
atoi.o: atoi.c ../../include/stdlib.h
getchar.o: getchar.c ../../include/stdio.h
gets.o: gets.c ../../include/stdint.h ../../include/kb.h \
 ../../include/stdio.h
memchr.o: memchr.c ../../include/string.h
memcmp.o: memcmp.c ../../include/string.h
memcpy.o: memcpy.c ../../include/string.h
memset.o: memset.c ../../include/string.h
printf.o: printf.c ../../include/stdio.h ../../include/stdarg.h putnum.h \
 ../../include/ctype.h ../../include/stdlib.h ../../include/string.h
putchar.o: putchar.c ../../include/vga.h ../../include/stdio.h
puts.o: puts.c ../../include/stdio.h
rand.o: rand.c ../../include/stdlib.h rnd.h
smemset.o: smemset.c ../../include/string.h
srand.o: srand.c ../../include/stdlib.h rnd.h
strchr.o: strchr.c ../../include/string.h
strcmp.o: strcmp.c ../../include/string.h
strcpy.o: strcpy.c ../../include/string.h
strlen.o: strlen.c ../../include/string.h
strncmp.o: strncmp.c ../../include/string.h
strtol.o: strtol.c ../../include/stdlib.h ../../include/string.h
tolower.o: tolower.c ../../include/ctype.h
toupper.o: toupper.c ../../include/ctype.h
