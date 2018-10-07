include Makefile.in

NAME =Ostoy32
BIN = $(NAME).img
INSTALLDIR =/data/mae

.PHONY: all clean update install uninstall lib lowlib tools

all:	$(BIN)

$(BIN): lib lowlib mbr/mbr kernel32/kernel32  app/app
	cat mbr/mbr kernel32/kernel32  app/app > $(BIN)

mbr/mbr:
	$(MAKE) -C mbr
	
kernel32/kernel32: lib lowlib
	$(MAKE) -C kernel32
	
	
app/app: lib lowlib
	$(MAKE) -C app
	
clean:
	rm -f $(BIN) *~ && $(MAKE) -C mbr clean  && $(MAKE) -C kernel32 clean && \
	$(MAKE) -C app clean && $(MAKE) -C lib clean && \
	$(MAKE) -C lowlib clean && $(MAKE) -C tools clean

lib: lowlib
	$(MAKE) -C lib install

tools:
	$(MAKE) -C tools

lowlib:
	$(MAKE) -C lowlib install
	
update:
	$(MAKE) clean && $(MAKE)

install: $(BIN)
	cp $(BIN) $(INSTALLDIR)

uninstall:
	rm -f $(INSTALLDIR)/$(BIN)


	
