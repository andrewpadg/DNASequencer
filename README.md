# DNASequencer
Compare DNA sequences in a text file and return the most common species

## Getting Started

These instructions will show you how to use the source files to run the program.

### Setup

What file directory should look like.

```
dna-alignment.h
dna-samples.txt
edit-distance.h
Makefile
main.cpp
util.h
```

### Running the program

#### 1.
Input DNA sequences in dna-samples.txt in this format

```
--"species name"
ACTGGTCAGTCACCCAAG....
--"species name"
TTGCAACGTCAAACCCAC....
```

#### 2.
Compile using Makefile.

```
make
```

#### 3.
Run program.

```
make run
```

Program will return the closest pair of species as well as the distance between the first species in the pair and all
other species in the text file.

## Design

The DNA sequencer uses Levenshtein Distance [(Wikipedia)](http://bit.ly/2AHHIvI) to find the distance between two DNA sequences.

### Mutation Costs
Exact match - 0
Substitution - 1
Deletion - 2
Insertion - 2

Insertions and deletions cost more because unlike a substituion which affects a single amino acid, they shift the whole amino chain by 1 place.

Species are never compared more than once to cut down on runtime.

## Authors

* **Andrew Padgett** - *Clemson University* [GitHub](https://github.com/andrewpadg/)
