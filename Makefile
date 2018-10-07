include Makefile.in

NAME =Ostoy32

BIN1 = $(NAME).hdd
BIN2 = $(NAME).img
INSTALLDIR =/data/mae

.PHONY: all clean update install uninstall lib lowlib tools

all:	$(BIN1) $(BIN2)
$(BIN1): lib lowlib mbr/mbr kernel32/kernel32 app/app
	cat mbr/mbr kernel32/kernel32 app/app > $(BIN1)

$(BIN2): lib lowlib mbr/mbr kernel32/kernel32  app/app
	cat mbr/mbr kernel32/kernel32  app/app > $(BIN2)

mbr/mbr:
	$(MAKE) -C mbr
	
kernel32/kernel32: lib lowlib
	$(MAKE) -C kernel32
	
	
app/app: lib lowlib tools
	$(MAKE) -C app
	
clean:
	rm -f $(BIN1) $(BIN2) *~ && $(MAKE) -C mbr clean  && $(MAKE) -C kernel32 clean && \
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

install: $(BIN1) $(BIN2)
	cp $(BIN1) $(INSTALLDIR) && cp $(BIN2) $(INSTALLDIR)

uninstall:
	rm -f $(INSTALLDIR)/$(BIN1)


	
