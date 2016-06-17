CC=gcc
CFLAGS=-Wall -ansi -pedantic
LDFLAGS=
PROGRAM=test_poisons_list

test_poisons_list: ../random/random.o ../position/position.o ../poison/poison.o test_poisons_list.o poisons_list.o
	$(CC) -o $(PROGRAM) $^

test_poisons_list.o: test_poisons_list.c
poisons_list.o: poisons_list.c

clean:
	cd ../random && make clean
	cd ../position && make clean
	cd ../poison && make clean
	rm -f *.o

uninstall:
	rm -f $(PROGRAM)
