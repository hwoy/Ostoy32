include ../../Makefile.in
include ../../Makefile.lib.in


CFLAGS += -D_SYSCALL_

listo = get_char.o kybrd_ctrl_read_status.o  kybrd_ctrl_send_cmd.o  kybrd_enc_read_buf.o  kybrd_enc_send_cmd.o

LIBNAME =libkb.a

.PHONY: all clean install update make-dep

all:	$(LIBNAME) 
$(LIBNAME):	$(listo)
	$(AR) -rc $(LIBNAME)  $(listo)
	
get_char.s: get_char.c
	$(CC) -S $(CFLAGS) get_char.c

install: all
		cp *.a ../

update:
		$(MAKE) clean && $(MAKE) install

clean:	
	rm -f *.o *.a *~ 

make-dep:
	$(MAKE) -MM $(CFLAGS) *.c

get_char.o: get_char.c ../../include/stdint.h ../../include/kb.h
kybrd_ctrl_read_status.o: kybrd_ctrl_read_status.c ../../include/asm.h \
 ../../include/stdint.h ../../include/kb.h
kybrd_ctrl_send_cmd.o: kybrd_ctrl_send_cmd.c ../../include/asm.h \
 ../../include/stdint.h ../../include/kb.h
kybrd_enc_read_buf.o: kybrd_enc_read_buf.c ../../include/asm.h \
 ../../include/stdint.h ../../include/kb.h
kybrd_enc_send_cmd.o: kybrd_enc_send_cmd.c ../../include/asm.h \
 ../../include/stdint.h ../../include/kb.h
