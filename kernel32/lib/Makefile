include ../../Makefile.in
.PHONY: all clean install update

all:
		$(MAKE) -C kprintf


clean:	
		$(MAKE) -C kprintf clean 

install: all
	$(MAKE) -C kprintf install

update:
		$(MAKE) clean && $(MAKE) install
	
