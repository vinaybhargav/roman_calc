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

#define NO_OF_DISTINCT_ROMANS 7


typedef struct
{
    char roman[100];
    int roman_in_int;
    int num_size;
}Roman_num;

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




/*
Does the roman calculation depending on operation.
Input = two roman arrays with(roman_num1 and roman_num2) their size(num1_size and num2_size) and operation(op). Currently supports add and subtract operations
Output = Returns a Roman_num type which contains the answer.
*/
Roman_num Roman_calc(char roman_num1[], char roman_num2[], int num1_size, int num2_size, char op);



/*
Checks the roman character array for errors. Errors like XXXX, CCCC, DD, LL etc.. are caught in this function.
Input = roman character array and its size.
Output = Returns 0 if the roman character has errors, else returns 1
*/
int check_for_errors(char roman_num[], int num_size);



/* A const table of distinct roman numbers. It looks like the following:
const Roman_num rt[7]  = {{{'I'},VAL_I,1},{{'V'},VAL_V,1},{{'X'},VAL_X,1},{{'L'},VAL_L,1},{{'C'},VAL_C,1},{{'D'},VAL_D,1},{{'M'},VAL_M,1}};*/
extern const Roman_num rt[NO_OF_DISTINCT_ROMANS];
