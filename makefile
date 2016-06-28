all_target=test1 candy  distinct_subsequences permutations jump_game \
	edit_distance first_missing_positive trapping_rain_water

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
