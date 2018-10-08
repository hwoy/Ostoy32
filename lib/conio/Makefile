include ../../Makefile.in
include ../../Makefile.lib.in

listo = clrscr.o  gotoxy.o  _setcursortype.o  textbackground.o  textcolor.o  wherex.o  wherey.o getch.o getche.o

LIBNAME =libconio.a

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

_setcursortype.o: _setcursortype.c ../../include/conio.h \
 ../../include/vga.h
clrscr.o: clrscr.c ../../include/conio.h ../../include/vga.h
getch.o: getch.c ../../include/conio.h ../../include/stdint.h \
 ../../include/kb.h
getche.o: getche.c ../../include/conio.h ../../include/stdint.h \
 ../../include/stdio.h ../../include/kb.h
gotoxy.o: gotoxy.c ../../include/conio.h ../../include/vga.h
textbackground.o: textbackground.c ../../include/conio.h \
 ../../include/vga.h
textcolor.o: textcolor.c ../../include/conio.h ../../include/vga.h
wherex.o: wherex.c ../../include/conio.h ../../include/vga.h
wherey.o: wherey.c ../../include/conio.h ../../include/vga.h
