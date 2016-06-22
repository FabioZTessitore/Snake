CC=gcc
CFLAGS=-Wall -ansi -pedantic

all: nc_snake.o snake.o

nc_snake.o: nc_snake.c

snake.o:
	cd ../../lib/snake && $(MAKE) all && cp ./*.o ../../nc_lib/nc_snake/

clean:
	cd ../../lib/snake && $(MAKE) clean
	rm -f *.o
