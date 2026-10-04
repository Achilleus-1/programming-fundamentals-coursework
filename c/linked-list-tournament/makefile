CC = gcc
CFLAGS = -std=c99

all: project3Exe

project3Exe: main.o champion.o
	$(CC) $(CFLAGS) -o project3Exe main.o champion.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

champion.o: champion.c champion.h
	$(CC) $(CFLAGS) -c champion.c

clean:
	rm -f *.o project3Exe

.PHONY: all clean