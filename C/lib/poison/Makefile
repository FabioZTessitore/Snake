CC=gcc
CFLAGS=-Wall -ansi -pedantic
LDFLAGS=
PROGRAM=test_poison

test_poison: ../random/random.o ../position/position.o test_poison.o poison.o
	$(CC) -o $(PROGRAM) $^

test_poison.o: test_poison.c
poison.o: poison.c

clean:
	cd ../random && make clean
	cd ../position && make clean
	rm -f *.o

uninstall:
	rm -f $(PROGRAM)
