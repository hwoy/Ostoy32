include ../../Makefile.in

CC=$(NATIVECC)
CFLAGS=-O2

bin = fstr

.PHONY: all clean

all: $(bin)

$(bin): main.o
	$(CC) -o $(bin) main.o

clean:
	rm -f $(bin) *.o *~


main.o: main.c
