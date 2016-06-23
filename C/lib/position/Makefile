CC=gcc
CFLAGS=-Wall -ansi -pedantic
PROGRAM=test_position

all: position.o

position.o: position.h position.c

test_position: test_position.o position.o
test_position.o: test_position.c

clean:
	rm -f *.o

uninstall:
	rm -f $(PROGRAM)
