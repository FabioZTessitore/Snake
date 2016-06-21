CC=gcc
CFLAGS=-Wall -ansi -pedantic
PROGRAM=test_snake

test_snake: ../position/position.o test_snake.o snake.o

test_snake.o: test_snake.c
snake.o: snake.c

clean:
	cd ../position && make clean
	rm -f *.o

uninstall:
	rm -f $(PROGRAM)
