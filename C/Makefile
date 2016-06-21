CC=gcc
CFLAGS=-Wall -ansi -pedantic
LDFLAGS=-lncurses
PROGRAM=snake

DEPS=main.o ./nc_lib/nc_snake/nc_snake.o ./nc_lib/nc_poisons_list/nc_poisons_list.o ./lib/poisons_list/poisons_list.o ./lib/snake/snake.o ./lib/position/position.o ./lib/poison/poison.o ./lib/random/random.o
all: snake.o poisons_list.o nc_snake.o nc_poisons_list.o main.o
	$(CC) $(LDFLAGS) -o $(PROGRAM) $(DEPS)

snake.o:
	cd ./lib/snake && $(MAKE) all

poisons_list.o:
	cd ./lib/poisons_list && $(MAKE) all

nc_snake.o:
	cd ./nc_lib/nc_snake && $(MAKE) all

nc_poisons_list.o:
	cd ./nc_lib/nc_poisons_list && $(MAKE) all

main.o: main.c

clean:
	cd ./lib/snake && $(MAKE) clean
	cd ./lib/poisons_list && $(MAKE) clean
	cd ./nc_lib/nc_poisons_list && $(MAKE) clean
	cd ./nc_lib/nc_snake && $(MAKE) clean
	rm -f *.o

uninstall:
	rm -f $(PROGRAM)
