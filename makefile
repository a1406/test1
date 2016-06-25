all: test1 candy  distinct_subsequences

clean:
	rm -rf test1 candy distinct_subsequences

test1: test1.c
	gcc -g -O0 -o test1 test1.c

candy: candy.c 
	gcc -g -O0 -o $@ $^

distinct_subsequences: distinct_subsequences.c
	gcc -g -O0 -o $@ $^
