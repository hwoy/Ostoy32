include ../../Makefile.in
include ../../Makefile.lib.in


listc = clrscr.c  gotoxy.c  _setcursortype.c  textbackground.c  textcolor.c  wherex.c  wherey.c getch.c getche.c
listo = clrscr.o  gotoxy.o  _setcursortype.o  textbackground.o  textcolor.o  wherex.o  wherey.o getch.o getche.o
LIBNAME =libconio.a

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
