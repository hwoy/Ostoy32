include ../../Makefile.in
include ../../Makefile.lib.in


listc = pix.c  disablecursor.c  get_cur.c  kputc.c  kputs.c  scrollup.c    set_cur.c set_bg.c set_fg.c set_cursize.c get_pix.c
listo = pix.o  disablecursor.o  get_cur.o  kputc.o  kputs.o  scrollup.o    set_cur.o set_bg.o set_fg.o set_cursize.o get_pix.o
LIBNAME =libvga.a

.PHONY: all clean install update obj

all:	$(LIBNAME) 
$(LIBNAME):	$(listo) asm.o
	$(AR) -rc $(LIBNAME)  $(listo) asm.o

$(listo): $(listc)
	$(CC) -c $(CFLAGS)    $(listc)
	
asm.o: asm.s
	$(AS) -o asm.o asm.s

install: all
		cp *.a ../

update:
		$(MAKE) clean && $(MAKE) install

clean:	
	rm -f *.o *.a *~ 
