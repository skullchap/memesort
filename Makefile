all:
	gcc -o a.out main.c misc.c memesort.c -O3
debug:
	gcc -o a.out main.c misc.c memesort.c -O0 -g