#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define VAL_I 1
#define VAL_V 5
#define VAL_X 10
#define VAL_L 50
#define VAL_C 100
#define VAL_D 500
#define VAL_M 1000


typedef struct
{
    char roman[100];
    int roman_in_int;
    int num_size;
}Roman_num;

/* A const table of distinct roman numbers. It looks like the following:
const Roman_num rt[7]  = {{{'I'},VAL_I,1},{{'V'},VAL_V,1},{{'X'},VAL_X,1},{{'L'},VAL_L,1},{{'C'},VAL_C,1},{{'D'},VAL_D,1},{{'M'},VAL_M,1}};*/
extern const Roman_num rt[7];


/*
Converts int to roman.
Input is a integer.
Output is of type Roman_num
*/
Roman_num int_to_roman(int num);



/*
Converts Roman to int
Input : Roman array of characters, and its array size
Output : integer equivalent of the input roman array.
*/
int roman_to_int(char roman_num[], int num_size);
