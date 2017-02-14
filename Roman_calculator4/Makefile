CC = gcc

FILES = test1.c Roman_calc.c

CFLAGS = -std=c99 -O2

OUT = -o test1.out

all:
	$(CC) $(FILES) $(CFLAGS) $(shell pkg-config --libs check) $(OUT)

clean:
	rm -rf *.out
