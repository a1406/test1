all_target=test1 candy  distinct_subsequences permutations jump_game \
	edit_distance first_missing_positive trapping_rain_water \
	text_justification shortest_palindrome self_crossing

all: $(all_target)

clean:
	rm -rf $(all_target)

test1: test1.c
	gcc -g -O0 -o test1 test1.c

candy: candy.c 
	gcc -g -O0 -o $@ $^

distinct_subsequences: distinct_subsequences.c
	gcc -g -O0 -o $@ $^

permutations: permutations.c
	gcc -g -O0 -o $@ $^

jump_game: jump_game.c
	gcc -g -O0 -o $@ $^

edit_distance: edit_distance.c
	gcc -g -O0 -o $@ $^

first_missing_positive: first_missing_positive.c 
	gcc -g -O0 -o $@ $^

trapping_rain_water: trapping_rain_water.c
	gcc -g -O0 -o $@ $^

text_justification: text_justification.c
	gcc -g -O0 -o $@ $^

shortest_palindrome: shortest_palindrome.c
	gcc -g -O0 -o $@ $^

self_crossing: self_crossing.c
	gcc -g -O0 -o $@ $^
