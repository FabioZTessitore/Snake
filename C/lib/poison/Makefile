CC=gcc
CFLAGS=-Wall -ansi -pedantic
PROGRAM=test_poison

test_poison: ../random/random.o test_poison.o poison.o

test_poison.o: test_poison.c
poison.o: poison.c

clean:
	cd ../random && make clean
	rm -f *.o

uninstall:
	rm -f $(PROGRAM)
