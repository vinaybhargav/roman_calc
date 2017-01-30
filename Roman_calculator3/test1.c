#include <check.h>

#include "Roman_calc.h"

//int_to_roman tests.
//Test1: check conversion for int above 1000.
START_TEST(test1)
{

	int num = 1900;
	Roman_num roman1;
	roman1 = int_to_roman(num);
	fail_unless(roman1.roman[0] == 'M');
	fail_unless(roman1.roman[1] == 'C');
	fail_unless(roman1.roman[2] == 'M');

}
END_TEST


//test2: check conversion for int below 1000, but with high roman character count.
START_TEST(test2)
{

	int num = 831;
	Roman_num roman2;
	roman2 = int_to_roman(num);
	fail_unless(roman2.roman[0] == 'D');
	fail_unless(roman2.roman[1] == 'C');
	fail_unless(roman2.roman[2] == 'C');
	fail_unless(roman2.roman[3] == 'C');
	fail_unless(roman2.roman[4] == 'X');
	fail_unless(roman2.roman[5] == 'X');
	fail_unless(roman2.roman[6] == 'X');
	fail_unless(roman2.roman[7] == 'I');

}
END_TEST

//test3: check for int less than 10.
START_TEST(test3)
{

	int num = 4;
	Roman_num roman3;
	roman3 = int_to_roman(num);
	fail_unless(roman3.roman[0] == 'I');
	fail_unless(roman3.roman[1] == 'V');

}
END_TEST


//test4: check for int which can be represnted by single roman character.
START_TEST(test4)
{

	int num = 50;
	Roman_num roman3;
	roman3 = int_to_roman(num);
	fail_unless(roman3.roman[0] == 'L');

}
END_TEST


//roman_to_int() tests
//test5: conversion of a roman number with high character count. 
START_TEST(test5)
{

	int num = 0;
	Roman_num roman = { { "MMMCMXXXIII" },0,11 };
	num = roman_to_int(roman.roman, roman.num_size);
	fail_unless(num == 3933);

}
END_TEST


//test6: conversion of smaller roman numeral
START_TEST(test6)
{

	int num = 0;
	Roman_num roman = { { "LIX" },0,3 };
	num = roman_to_int(roman.roman, roman.num_size);
	fail_unless(num == 59);


}
END_TEST


//Test cases for check_for_errors() function
//test7: Check on valid roman numeral.
START_TEST(test7)
{

	int num = 0;
	Roman_num roman = {{"LIX"},0,3};
	num = check_for_errors(roman.roman,roman.num_size);
	fail_unless(num == 1);

}
END_TEST

//test8: check on an invalid string.
START_TEST(test8)
{

	int num = 0;
	num = check_for_errors("Hi",2);
	fail_unless(num == 0);

}
END_TEST


//test9: check on lower case characters. Roman case did not use lower case.
START_TEST(test9)
{

	int num = 0;
	num = check_for_errors("mmmcm",5); //lowercase should give error
	fail_unless(num == 0);

}
END_TEST

//test10: check on contiguous L. LL = 100 = C. Therefore, LL is invalid.
START_TEST(test10)
{

	int num = 0;
	num = check_for_errors("LL",2);
	fail_unless(num == 0);

}
END_TEST

//test11: check on contiguous C. CCCC = 400 = CD. Therefore, CCCC invalid representation.
START_TEST(test11)
{
	int num = 0;
	num = check_for_errors("CCCC",4);
	fail_unless(num == 0);

}
END_TEST

//test12: Check on contiguous M. Contoguous M are valid. So there should be no errors.
START_TEST(test12)
{
	int num = 0;
	num = check_for_errors("MMMMM",5);
	fail_unless(num == 1);  
}
END_TEST

int main(void)
{
	Suite *s1 = suite_create("Suite1");
	TCase *tc1_1 = tcase_create("int_to_roman_test");
	TCase *tc1_2 = tcase_create("roman_to_int_test");
	TCase *tc1_3 = tcase_create("check_for_errors_in_input");
	SRunner *sr = srunner_create(s1);
	int nf;

	suite_add_tcase(s1, tc1_1);
	tcase_add_test(tc1_1, test1);
	tcase_add_test(tc1_1, test2);
	tcase_add_test(tc1_1, test3);
	tcase_add_test(tc1_1, test4);
	suite_add_tcase(s1, tc1_2);
	tcase_add_test(tc1_2, test5);
	tcase_add_test(tc1_2, test6);
	suite_add_tcase(s1, tc1_3);
	tcase_add_test(tc1_3, test7);
	tcase_add_test(tc1_3, test8);
	tcase_add_test(tc1_3, test9);
	tcase_add_test(tc1_3, test10);
	tcase_add_test(tc1_3, test11);
	tcase_add_test(tc1_3, test12);

	srunner_run_all(sr, CK_ENV);
	nf = srunner_ntests_failed(sr);
	srunner_free(sr);

	return nf == 0 ? 0 : 1;
}
