all:
	gcc -o a.out main.c misc.c memesort.c -Wall -O3
debug:
	gcc -o a.out main.c misc.c memesort.c -Wall -O0 -g