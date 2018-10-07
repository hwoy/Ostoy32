include ../../Makefile.in
bin = fstr

.PHONY: all clean

all: $(bin)

$(bin): main.o
	$(CC) -o $(bin) main.o

main.o: main.c
	$(CC) -c -O2 main.c

clean:
	rm -f $(bin) *.o *~


