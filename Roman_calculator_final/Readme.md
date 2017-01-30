# Roman calculator library

Provides APIs to operate on roman numerals.

Following operations are supported in this library.

1. Convert roman to int.

2. Convert int to roman.

3. Check if a roman numeral is error free according to the following rules.

    a. Roman numerals are all upper case alphabets.
    
    b. Contains only I,V,X,L,C,D,M characters.
    
    c. I,X,C are not repeated 4 times contiguously.
    
    d. V,L,D are not repeated 2 times contiguously.
    
4. Perform + or - operation.

Check the Roman_calc.h header file for more info.


#How to use?

input roman1;

check_for_errors(roman1);

input roman2;

check_for_errors(roman2);

roman_to_int(roman1);

roman_to_int(roman2);

answer = <Perform your operation on roman1 and roman2>;

int_to_roman(answer);
