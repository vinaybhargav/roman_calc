#include "include/Roman_calc.h"

const Roman_num rt[NO_OF_DISTINCT_ROMANS]  = {{{'I'},VAL_I,1},{{'V'},VAL_V,1},{{'X'},VAL_X,1},{{'L'},VAL_L,1},{{'C'},VAL_C,1},{{'D'},VAL_D,1},{{'M'},VAL_M,1}};

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
    R.roman[0] = 0;
    R.roman_in_int = num;
    R.num_size = 0;
    num = abs(num);
    for(int i = NO_OF_DISTINCT_ROMANS-1; i > -1 ; i--)
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

/*
This function looks one character forward in the Roman char array to determine if there is a bigger roman number, so as to find cases like IV, IX, CM
Inputs : current = index of current Roman according to table.
         next_roman = roman character which is one ahead in the array.(see roman_to_int() for example.)

Output: is a flag 1 or 0 indicating true or false respectively. If return value = 1 then the input next_roman is bigger than the previous roman character in array.
*/
int look_forward_for_bigger_roman(int current, char next_roman)
{
    for(int i = current+1; i < NO_OF_DISTINCT_ROMANS; i++)
    {
        if(next_roman == rt[i].roman[0])
            return 1;
    }
    return 0;
}

/*
Converts Roman to int
Input : Roman array of characters, and its array size
Output : integer equivalent of the input roman array.
*/
int roman_to_int(char roman_num[],int num_size)
{
    int num = 0;

    for(int i = 0; i < num_size; i++)
    {
        int ret = 0;
        for(int j = 0; j < NO_OF_DISTINCT_ROMANS ; j++ )
        {
            if(roman_num[i] == rt[j].roman[0])
            {
                if(i+1 < num_size)
                    ret = look_forward_for_bigger_roman(j,roman_num[i+1]);

                num = ret > 0 ? num - rt[j].roman_in_int : num + rt[j].roman_in_int;
            }
        }
    }

    return num;
}


/*
Validates character for being a roman character or not.
Input = c which is a character in roman number array.
Output = Returns 0 if the character is valid, else returns 1;
*/
int validate_roman_char(char c)
{
    if(c == 'I' || c == 'V' || c == 'X' || c == 'L' ||  c == 'C' || c == 'D' || c == 'M')
        return 0;
    else
        return 1;
}


/*
Checks the roman character array for errors. Errors like XXXX, CCCC, DD, LL etc.. are caught in this function.
Input = roman character array and its size.
Output = Returns 0 if the roman character has errors, else returns 1
*/
int check_for_errors(char roman_num[], int num_size)
{
    for(int i = 0; i < num_size; i++)
    {
        int ret = validate_roman_char(roman_num[i]);
        if(ret)
        {
            printf("Invalid Roman number.\n");
            return 0;
        }
        for(int j = 0; j < NO_OF_DISTINCT_ROMANS-1; j++)
        {
            if(roman_num[i] == rt[j].roman[0])
            {
                if((i+3) < num_size && j%2 == 0)
                {
                    if (roman_num[i + 1] == rt[j].roman[0] && roman_num[i + 2] == rt[j].roman[0] && roman_num[i + 3] == rt[j].roman[0])
                    {
                        printf("Invalid Roman number.\n");
                        return 0;
                    }
                }
                else if((i+1) < num_size && j%2 == 1)
                {
                    if (roman_num[i + 1] == rt[j].roman[0] || roman_num[i + 1] == rt[j+1].roman[0])
                    {
                        printf("Invalid Roman number.\n");
                        return 0;
                    }
                }
            }
        }
    }

    return 1;
}


/*
Does the roman calculation depending on operation.
Input = two roman arrays with(roman_num1 and roman_num2) their size(num1_size and num2_size) and operation(op). Currently supports add and subtract operations
Output = Returns a Roman_num type which contains the answer.
*/
Roman_num Roman_calc(char roman_num1[], char roman_num2[], int num1_size, int num2_size, char op)
{
    int num1 = 0, num2 = 0, answer = 0;

    num1 = roman_to_int(roman_num1, num1_size);
    num2 = roman_to_int(roman_num2, num2_size);

    if(op == '+')
    {
        answer = num1 + num2;
    }
    else if(op == '-')
    {
        answer = num1 - num2;
    }
    else
    {
        printf("Operation not supported\n");
    }
    return int_to_roman(answer);
}
