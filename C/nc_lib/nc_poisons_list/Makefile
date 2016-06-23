CC=gcc
CFLAGS=-Wall -ansi -pedantic

all: nc_poisons_list.o poisons_list.o

nc_poisons_list.o: nc_poisons_list.h nc_poisons_list.c

poisons_list.o:
	cd ../../lib/poisons_list && $(MAKE) all && cp ./*.o ../../nc_lib/nc_poisons_list/

clean:
	cd ../../lib/poisons_list && $(MAKE) clean
	rm -f *.o
