CC=gcc
CFLAGS=-Wall -ansi -pedantic
LDFLAGS=-lncurses
PROGRAM=snake

DEPS=main.o ./nc_lib/nc_snake/nc_snake.o ./lib/snake/snake.o ./lib/position/position.o
all: snake.o nc_snake.o main.o
	$(CC) $(LDFLAGS) -o $(PROGRAM) $(DEPS)

snake.o:
	cd ./lib/snake && $(MAKE) all

nc_snake.o:
	cd ./nc_lib/nc_snake && $(MAKE) all

main.o: main.c

clean:
	cd ./lib/snake && $(MAKE) clean
	cd ./nc_lib/nc_snake && $(MAKE) clean
	rm -f *.o

uninstall:
	rm -f $(PROGRAM)
