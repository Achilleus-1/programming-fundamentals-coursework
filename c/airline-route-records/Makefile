CC=gcc
CFLAGS=-I. -std=c99

all: program

program: main.o route-records.o
	$(CC) -o program main.o route-records.o $(CFLAGS)

main.o: main.c
	$(CC) -c main.c $(CFLAGS)

route-records.o: route-records.c
	$(CC) -c route-records.c $(CFLAGS)

clean:
	rm -f *.o program
