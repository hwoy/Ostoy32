include ../../Makefile.in
include ../../Makefile.lib.in

listo = pix.o  disablecursor.o  get_cur.o  kputc.o  kputs.o  scrollup.o    set_cur.o set_bg.o set_fg.o set_cursize.o get_pix.o

LIBNAME =libvga.a

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

disablecursor.o: disablecursor.c ../../include/vga.h ../../include/asm.h \
 ../../include/stdint.h
get_cur.o: get_cur.c ../../include/vga.h ../../include/asm.h \
 ../../include/stdint.h
get_pix.o: get_pix.c ../../include/vga.h
kputc.o: kputc.c ../../include/vga.h ../../include/asm.h \
 ../../include/stdint.h
kputs.o: kputs.c ../../include/vga.h ../../include/asm.h \
 ../../include/stdint.h
pix.o: pix.c ../../include/vga.h ../../include/asm.h \
 ../../include/stdint.h
scrollup.o: scrollup.c ../../include/vga.h ../../include/asm.h \
 ../../include/stdint.h
set_bg.o: set_bg.c ../../include/vga.h
set_cur.o: set_cur.c ../../include/vga.h ../../include/asm.h \
 ../../include/stdint.h
set_cursize.o: set_cursize.c ../../include/vga.h ../../include/asm.h \
 ../../include/stdint.h
set_fg.o: set_fg.c ../../include/vga.h
