include ../../Makefile.in
include ../../Makefile.lib.in


CFLAGS += -D_SYSCALL_

listc = get_char.c kybrd_ctrl_read_status.c  kybrd_ctrl_send_cmd.c  kybrd_enc_read_buf.c  kybrd_enc_send_cmd.c
listo = get_char.o kybrd_ctrl_read_status.o  kybrd_ctrl_send_cmd.o  kybrd_enc_read_buf.o  kybrd_enc_send_cmd.o
LIBNAME =libkb.a

.PHONY: all clean install update

all:	$(LIBNAME) 
$(LIBNAME):	$(listo) asm.o
	$(AR) -rc $(LIBNAME)  $(listo) asm.o

$(listo): $(listc)
	$(CC) -c $(CFLAGS)    $(listc)
	
get_char.s: get_char.c
	$(CC) -S $(CFLAGS) get_char.c
asm.o: asm.s
	$(AS) -o asm.o asm.s

install: all
		cp *.a ../

update:
		$(MAKE) clean && $(MAKE) install

clean:	
	rm -f *.o *.a *~ 
