CC = gcc

AR = ar

FILES = Roman_calc.c

CFLAGS = -O2 -c -lcheck

ARFLAGS = rcs


all: Roman_calc.c
	$(CC) $(FILES) $(CFLAGS) -o libs/Roman_calc.o
	$(AR) $(ARFLAGS) libs/libRoman_calc.a libs/Roman_calc.o

clean:
	rm -rf *.o
	rm -rf *.a
