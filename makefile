all: test1

clean:
	rm -rf test1

test1: test1.c
	gcc -g -O0 -o test1 test1.c

