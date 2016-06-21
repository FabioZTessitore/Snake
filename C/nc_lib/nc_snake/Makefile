CC=gcc
CFLAGS=-Wall -ansi -pedantic

all: nc_snake.o snake.o

nc_snake.o: nc_snake.c

snake.o:
	cd ../../lib/snake && $(MAKE) all

clean:
	cd ../../lib/snake && $(MAKE) clean
	rm -f *.o
