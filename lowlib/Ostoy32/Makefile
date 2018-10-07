include ../../Makefile.in
include ../../Makefile.lib.in


CFLAGS +=  -D_SYSCALL_

listc = disablecursor.c  get_cur.c  kputc.c  kputs.c  scall.c  scrollup.c  set_bg.c  set_cur.c  set_cursize.c  set_fg.c pix.c get_pix.c get_char.c get_driveno.c delay.c get_timetick.c
listo = disablecursor.o  get_cur.o  kputc.o  kputs.o  scall.o  scrollup.o  set_bg.o  set_cur.o  set_cursize.o  set_fg.o pix.o get_pix.o get_char.o get_driveno.o delay.o get_timetick.o
LIBNAME =libOstoy32.a

.PHONY: all clean install update

all:	$(LIBNAME) 
$(LIBNAME):	$(listo)
	$(AR) -rc $(LIBNAME)  $(listo)

$(listo): $(listc)
	$(CC) -c $(CFLAGS)    $(listc)
	
scall.s:
	$(CC) -S $(CFLAGS)    $(listc)

install: all
		cp *.a ../

update:
		$(MAKE) clean && $(MAKE) install

clean:	
	rm -f *.o *.a *~ 
