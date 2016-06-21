CC=gcc
CFLAGS=-Wall -ansi -pedantic
PROGRAM=test_poisons_list

all: poisons_list.o poison.o

test_poisons_list: ../poison/poison.o test_poisons_list.o poisons_list.o

test_poisons_list.o: test_poisons_list.c

poisons_list.o: poisons_list.c
poison.o:
	cd ../poison && $(MAKE) all

clean:
	cd ../poison && $(MAKE) clean
	rm -f *.o

uninstall:
	rm -f $(PROGRAM)
