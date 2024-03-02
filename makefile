CC = gcc
CFLAGS = -Wall 

all: digitcompress

digitcompress: encodemain.o compress.o
	$(CC) -o digitcompress encodemain.o compress.o

encodemain.o: encodemain.c compress.h
	$(CC) $(CFLAGS) -c encodemain.c

compress.o: compress.c compress.h
	$(CC) $(CFLAGS) -c compress.c

clean:
	rm -f *.o digitcompress
