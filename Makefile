all: main.c misc.c srt.c
	gcc -o a.out main.c misc.c srt.c -O3
debug: main.c misc.c srt.c
	gcc -o a.out main.c misc.c srt.c -g