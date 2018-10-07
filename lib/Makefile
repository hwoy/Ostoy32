include ../Makefile.in
.PHONY: all clean install update

all:
		$(MAKE) -C cpuid && \
$(MAKE) -C libc && \
$(MAKE) -C conio

clean:	
		$(MAKE) -C cpuid clean && \
$(MAKE) -C libc clean && \
$(MAKE) -C conio clean && rm -rf *.a

install: all
		$(MAKE) -C cpuid install && \
$(MAKE) -C libc install && \
$(MAKE) -C conio install

update:
		$(MAKE) clean && $(MAKE) install
	
