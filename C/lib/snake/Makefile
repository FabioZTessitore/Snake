CC=gcc
CFLAGS=-Wall -ansi -pedantic
PROGRAM=test_snake

all: snake.o position.o

snake.o: snake.h snake.c

position.o:
	cd ../position && $(MAKE) all && cp ./*.o ../snake/

test_snake: ../position/position.o test_snake.o snake.o
test_snake.o: test_snake.c

clean:
	cd ../position && $(MAKE) clean
	rm -f *.o

uninstall:
	rm -f $(PROGRAM)
