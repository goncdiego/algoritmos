CC=gcc
CFLAGS=-I.

tp: TpGrafos.o mlists.o tools.o
	$(CC) -o tp TpGrafos.o mlists.o tools.o

clean:
	rm -rf tp TpGrafos.o mlists.o tools.o