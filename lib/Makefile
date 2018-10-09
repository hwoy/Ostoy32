include ../Makefile.in
.PHONY: all clean install update ar-list

all:
		$(MAKE) -C cpuid && \
$(MAKE) -C libc && \
$(MAKE) -C conio

clean:	
		$(MAKE) -C cpuid clean && \
$(MAKE) -C libc clean && \
$(MAKE) -C conio clean && $(MAKE) -C Ostoy32 clean && rm -rf *.a *.txt

install: all
		$(MAKE) -C cpuid install && \
$(MAKE) -C libc install && \
$(MAKE) -C conio install && $(MAKE) -C Ostoy32 install 

update:
		$(MAKE) clean && $(MAKE) install
	
ar-list: install
	ls *.a | xargs -I{} $(AR) -t {}
