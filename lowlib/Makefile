include ../Makefile.in
.PHONY: all clean install update

clean:
	$(MAKE) -C vga clean && $(MAKE) -C Ostoy32 clean && $(MAKE) -C kb clean && $(MAKE) -C boot clean && $(MAKE) -C timer clean && \
	rm -rf *.a

install: all
	$(MAKE) -C vga install && $(MAKE) -C Ostoy32 install && $(MAKE) -C kb install && $(MAKE) -C boot install && $(MAKE) -C timer install

update:
		$(MAKE) clean && $(MAKE) install
	
