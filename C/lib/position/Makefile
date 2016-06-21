CC=gcc
CFLAGS=-Wall -ansi -pedantic
PROGRAM=test_position

all: position.o

test_position: test_position.o position.o
	$(CC) -o $(PROGRAM) $^
test_position.o: test_position.c

position.o: position.c

clean:
	rm -f *.o

uninstall:
	rm -f $(PROGRAM)
