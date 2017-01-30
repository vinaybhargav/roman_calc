#include "Roman_calc.h"

const Roman_num rt[7]  = {{{'I'},VAL_I,1},{{'V'},VAL_V,1},{{'X'},VAL_X,1},{{'L'},VAL_L,1},{{'C'},VAL_C,1},{{'D'},VAL_D,1},{{'M'},VAL_M,1}};

/*
Finds out cases like IV, IC, IX, where there should be a smaller Roman before a larger.
Used to convert integer to roman correctly.
*/
char close_to_roman(int look_close, int current_roman_value, int *num)
{
    int temp;
    for(int i = 0; i < look_close; i++)
    {
        if(i == 0)
        {
            temp = 0;
        }
        else
        {
            temp = rt[i-1].roman_in_int;
        }
        if((*num % (current_roman_value - rt[i].roman_in_int )) < (rt[i].roman_in_int - temp))
        {
            *num -= (current_roman_value - rt[i].roman_in_int);
            return rt[i].roman[0];
        }
    }
    return 0;
}

/*
Converts int to roman.
Input is a integer.
Output is of type Roman_num
*/
Roman_num int_to_roman(int num)
{
    int temp_num = 0, look_close;
    Roman_num R;
    R.roman_in_int = num;
    R.num_size = 0;
    for(int i = 6; i > -1 ; i--)
    {
        if(num > 0)
        {
            if(num >= rt[i].roman_in_int)
            {
                temp_num = num / rt[i].roman_in_int;
                for(int j = 0; j < temp_num ; j++)
                {
                    R.roman[R.num_size] = rt[i].roman[0];
                    R.num_size++;
                }
                num = num % rt[i].roman_in_int;
            }
            look_close = 0;
            if(num >= (VAL_D - VAL_C))
            {
                look_close = 5;
            }
            else if(num >= (VAL_L - VAL_X))
            {
                look_close = 3;
            }
            else if(num >= (VAL_V - VAL_I))
            {
                look_close = 1;
            }
            char c = close_to_roman(look_close,rt[i].roman_in_int,&num);
            if(c)
            {
                R.roman[R.num_size] = c;
                R.roman[R.num_size+1] = rt[i].roman[0];
                R.num_size+=2;
            }
        }
        else
        {
            break;
        }
    }
    return R;
}
