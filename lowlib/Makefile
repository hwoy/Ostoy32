include ../Makefile.in
.PHONY: all clean install update ar-list

clean:
	$(MAKE) -C vga clean && $(MAKE) -C Ostoy32 clean && $(MAKE) -C kb clean && $(MAKE) -C boot clean && $(MAKE) -C timer clean && $(MAKE) -C asm clean &&\
	rm -rf *.a *.txt

install: all
	$(MAKE) -C vga install && $(MAKE) -C Ostoy32 install && $(MAKE) -C kb install && $(MAKE) -C boot install && $(MAKE) -C timer install && $(MAKE) -C asm install

update:
		$(MAKE) clean && $(MAKE) install
	
ar-list: install
	ls *.a | xargs -I{} $(AR) -t {}
