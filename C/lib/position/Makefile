CC=gcc
CFLAGS=-Wall -ansi -pedantic
LDFLAGS=
PROGRAM=test_position

test_position: test_position.o position.o
	$(CC) -o $(PROGRAM) $^

test_position.o: test_position.c
position.o: position.c

clean:
	rm -f *.o

uninstall:
	rm -f $(PROGRAM)
