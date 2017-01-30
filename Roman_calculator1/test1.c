#include <check.h>

#include "Roman_calc.h"


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

START_TEST(test3)
{

	int num = 4;
	Roman_num roman3;
	roman3 = int_to_roman(num);
	fail_unless(roman3.roman[0] == 'I');
    	fail_unless(roman3.roman[1] == 'V');

}
END_TEST

START_TEST(test4)
{

	int num = 50;
	Roman_num roman3;
	roman3 = int_to_roman(num);
	fail_unless(roman3.roman[0] == 'L');
	
    
}
END_TEST

int main(void)
{
    Suite *s1 = suite_create("Suite1");
    TCase *tc1_1 = tcase_create("int_to_roman_test");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, test1);
    tcase_add_test(tc1_1, test2);
    tcase_add_test(tc1_1, test3);
    tcase_add_test(tc1_1, test4);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
