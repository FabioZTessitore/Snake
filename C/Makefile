CC=gcc
CFLAGS=-Wall -ansi -pedantic
LDFLAGS=-lncurses
PROGRAM=snake

all: main.o nc_snake.o nc_poisons_list.o
	$(CC) $(LDFLAGS) *.o -o $(PROGRAM)

nc_snake.o:
	cd ./nc_lib/nc_snake && $(MAKE) all && cp ./*.o ../../

nc_poisons_list.o:
	cd ./nc_lib/nc_poisons_list && $(MAKE) all && cp ./*.o ../../

main.o: main.c

clean:
	cd ./nc_lib/nc_poisons_list && $(MAKE) clean
	cd ./nc_lib/nc_snake && $(MAKE) clean
	rm -f *.o

uninstall:
	rm -f $(PROGRAM)
