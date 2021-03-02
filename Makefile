all: main.c misc.c memesort.c
	gcc -o a.out main.c misc.c memesort.c -O3
debug: main.c misc.c memesort.c
	gcc -o a.out main.c misc.c memesort.c -g