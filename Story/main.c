#include "include/Roman_calc.h"

int main()
{
    int num1_size = 0, num2_size = 0, input_is_correct = 0;
    char roman_num1[100], roman_num2[100], op = 0;
    Roman_num answer;
    printf("Enter 1st Roman number\n");
    while(!input_is_correct)
    {
        while(1)
        {
            char c = getchar();
            if(c == '\n')
            {
                break;
            }
            roman_num1[num1_size] = c;
            num1_size++;
        }
        input_is_correct = check_for_errors(roman_num1,num1_size);
        if(!input_is_correct)
        {
            num1_size = 0;
        }
    }
    input_is_correct = 0;
    printf("Enter 2nd Roman Number\n");
    while(!input_is_correct)
    {
        while(1)
        {
            char c = getchar();
            if(c == '\n')
            {
                break;
            }
            roman_num2[num2_size] = c;
            num2_size++;
        }
        input_is_correct = check_for_errors(roman_num2,num2_size);
        if(!input_is_correct)
        {
            num2_size = 0;
        }
    }
    printf("Enter operation (+ or -)\n");
    while(1)
    {
        op = getchar();
        if(op == '+' || op == '-')
        {
            break;
        }
        else
        {
            printf("Wrong Operation entered. Try again\n");
        }
    }
    answer = Roman_calc(roman_num1, roman_num2, num1_size, num2_size, op);
	
	if(answer.roman_in_int < 0)
	{
		printf("Answer : Nulla. Romans did not know how to represent -ve or 0. But printing the answer\n");
		printf("-");
	}
	else
	{
		printf("Answer : ");
	}

	for(int i = 0; i < answer.num_size; i++)
	{
		printf("%c", answer.roman[i]);
	}
    printf("\n");
    return 0;
}
