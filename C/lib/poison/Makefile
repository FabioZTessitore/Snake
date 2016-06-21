CC=gcc
CFLAGS=-Wall -ansi -pedantic
PROGRAM=test_poison

all:  poison.o random.o

test_poison: ../random/random.o test_poison.o poison.o
test_poison.o: test_poison.c

poison.o: poison.c

random.o:
	cd ../random && $(MAKE) random.o

clean:
	cd ../random && $(MAKE) clean
	rm -f *.o

uninstall:
	rm -f $(PROGRAM)
