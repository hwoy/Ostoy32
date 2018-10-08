include ../../Makefile.in
include ../../Makefile.lib.in


CFLAGS +=  -D_SYSCALL_


listo = disablecursor.o  get_cur.o  kputc.o  kputs.o  scall.o  scrollup.o  set_bg.o  set_cur.o  set_cursize.o  set_fg.o pix.o get_pix.o get_char.o get_driveno.o delay.o get_timetick.o

LIBNAME =libOstoy32.a

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


delay.o: delay.c ../../include/Ostoy32.h ../../include/stdint.h \
 ../../include/vga.h ../../include/kb.h ../../include/boot.h \
 ../../include/timer.h
disablecursor.o: disablecursor.c ../../include/Ostoy32.h \
 ../../include/stdint.h ../../include/vga.h ../../include/kb.h \
 ../../include/boot.h ../../include/timer.h
get_char.o: get_char.c ../../include/Ostoy32.h ../../include/stdint.h \
 ../../include/vga.h ../../include/kb.h ../../include/boot.h \
 ../../include/timer.h
get_cur.o: get_cur.c ../../include/Ostoy32.h ../../include/stdint.h \
 ../../include/vga.h ../../include/kb.h ../../include/boot.h \
 ../../include/timer.h
get_driveno.o: get_driveno.c ../../include/Ostoy32.h \
 ../../include/stdint.h ../../include/vga.h ../../include/kb.h \
 ../../include/boot.h ../../include/timer.h
get_pix.o: get_pix.c ../../include/Ostoy32.h ../../include/stdint.h \
 ../../include/vga.h ../../include/kb.h ../../include/boot.h \
 ../../include/timer.h
get_timetick.o: get_timetick.c ../../include/Ostoy32.h \
 ../../include/stdint.h ../../include/vga.h ../../include/kb.h \
 ../../include/boot.h ../../include/timer.h
kputc.o: kputc.c ../../include/Ostoy32.h ../../include/stdint.h \
 ../../include/vga.h ../../include/kb.h ../../include/boot.h \
 ../../include/timer.h
kputs.o: kputs.c ../../include/Ostoy32.h ../../include/stdint.h \
 ../../include/vga.h ../../include/kb.h ../../include/boot.h \
 ../../include/timer.h
pix.o: pix.c ../../include/Ostoy32.h ../../include/stdint.h \
 ../../include/vga.h ../../include/kb.h ../../include/boot.h \
 ../../include/timer.h
scall.o: scall.c ../../include/Ostoy32.h ../../include/stdint.h \
 ../../include/vga.h ../../include/kb.h ../../include/boot.h \
 ../../include/timer.h
scrollup.o: scrollup.c ../../include/vga.h ../../include/asm.h \
 ../../include/stdint.h
set_bg.o: set_bg.c ../../include/vga.h
set_cur.o: set_cur.c ../../include/Ostoy32.h ../../include/stdint.h \
 ../../include/vga.h ../../include/kb.h ../../include/boot.h \
 ../../include/timer.h
set_cursize.o: set_cursize.c ../../include/Ostoy32.h \
 ../../include/stdint.h ../../include/vga.h ../../include/kb.h \
 ../../include/boot.h ../../include/timer.h
set_fg.o: set_fg.c ../../include/vga.h
