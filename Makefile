CC = g++
DEBUG = -g
CFLAGS = -Wall -std=gnu++11 $(DEBUG)
LFLAGS = -Wall $(DEBUG)

compile: dna.out

dna.out: main.cpp dna_alignment.h edit_distance.h util.h
	$(CC) $(CFLAGS) -o dna.out main.cpp

run: dna.out
	./dna.out

clean:
	rm *.out
