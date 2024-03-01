all: digitcompress

digitcompress: encodemain.o compress.o
	gcc -o digitcompress encodemain.o compress.o

encodemain.o: encodemain.c compress.h
	gcc -c encodemain.c

compress.o: compress.c compress.h
	gcc -c compress.c

clean:
	rm -f *.o digitcompress
