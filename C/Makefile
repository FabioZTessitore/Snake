CFLAGS=-Wall -ansi
LDFLAGS=
PROGRAM=

test: test_position

test_position:
	cd ./lib/position && make test_position && cp ./test_position ../../

clean:
	rm -rf test_position
	cd ./lib/position && make clean && make uninstall;
