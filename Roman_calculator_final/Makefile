CC = gcc

AR = ar

FILES = Roman_calc.c

CFLAGS = -O2 -c -std=c99

ARFLAGS = rcs

all: libs test

libs: Roman_calc.c
	$(CC) $(FILES) $(CFLAGS) -o libs/Roman_calc.o
	$(AR) $(ARFLAGS) libs/libRoman_calc.a libs/Roman_calc.o

test: test1.c
	$(CC) test1.c $(FILES) -O3 $(shell pkg-config --libs check) -o test1.out

clean:
	rm -rf *.out
