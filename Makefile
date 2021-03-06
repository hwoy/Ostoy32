include Makefile.in

NAME =Ostoy32
BIN = $(NAME).img
INSTALLDIR =img
APP=app

QEMU="/c/Program Files/qemu/qemu-system-i386w.exe"

.PHONY: all clean update install uninstall lib tools run

all: $(BIN)

$(BIN): lib mbr/mbr kernel32/kernel32  $(APP)/app
	cat mbr/mbr kernel32/kernel32  $(APP)/app > $(BIN)

mbr/mbr:
	$(MAKE) -C mbr
	
kernel32/kernel32: lib  
	$(MAKE) -C kernel32

	
clean:
	rm -f $(BIN) *~ && $(MAKE) -C mbr clean  && $(MAKE) -C kernel32 clean && \
	$(MAKE) -C app clean && $(MAKE) -C lib clean && $(MAKE) -C tools clean && $(MAKE) -C app-cpp clean

lib:
	$(MAKE) -C lib install

tools:
	$(MAKE) -C tools
	
update:
	$(MAKE) clean && $(MAKE)

install: $(BIN)
	cp $(BIN) $(INSTALLDIR)

uninstall:
	rm -f $(INSTALLDIR)/$(BIN)

run: $(BIN)
	$(QEMU) -drive file=$(BIN),format=raw


######################## Application ######################## 

app/app: lib  
	$(MAKE) -C app

app-cpp/app: lib
	$(MAKE) -C app-cpp
	
	


	
