/*--------------------------------------------------------

WorkSheet 9 part 2 (Word Boundary Optimization)
Developper : Moshé
Viewer : 
Status : Dev

--------------------------------------------------------*/
#include <stdio.h> /* printf */
#include "atoi.h"

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"

void TestAtoi();
void TestItoa();
void TestItoa36();

enum end_process
{
	SUCCESS = 0, FAILED = 1, EXIT_PROG = 2
};

int main(void)
{
	TestAtoi();
	TestItoa();
	TestItoa36();
	
	return SUCCESS;
}

void TestAtoi(void)
{
	int test1 = 123;
	int test2 = -123;
	int test3 = 0;
	int test4 = 1;
	int test5 = -45;
	char test6[5] = "1212";
	
	printf(""KBLU"--------TEST ATOI--------"KNRM"\n\n");
	if (Atoi("123") == test1)
	{
		printf(""KGRN"SUCCES"KNRM" for 123, result : 123 \n");
	}
	else
	{
		printf(""KRED"FAILED\n"KNRM"");
	}
	if (Atoi("-123") == test2)
	{
		printf(""KGRN"SUCCES"KNRM" for -123, result : -123 \n");
	}
	else
	{
		printf(""KRED"FAILED\n"KNRM"");
	}
	if (Atoi("A123") == test3)
	{
		printf(""KGRN"SUCCES"KNRM" for A123, result : 0 \n");
	}
	else
	{
		printf(""KRED"FAILED\n"KNRM"");
	}
	if (Atoi("1a234") == test4)
	{
		printf(""KGRN"SUCCES"KNRM" for 1a234 result : 1 \n");
	}
	else
	{
		printf(""KRED"FAILED\n"KNRM"");
	}
	if (Atoi("-45-45") == test5)
	{
		printf(""KGRN"SUCCES"KNRM" for -45-45 result : -45 \n");
	}
	else
	{
		printf(""KRED"FAILED\n"KNRM"");
	}
	if (Atoi(test6) == 1212)
	{
		printf(""KGRN"SUCCES"KNRM" for (space)1212 result : 1212 \n");
	}
	else
	{
		printf(""KRED"FAILED\n"KNRM"");
	}

}

void TestItoa(void)
{
	int value = 123456;
	int value2 = -124;
	char s[100];	
	
	printf(""KBLU"--------TEST ITOA--------"KNRM"\n\n");
	printf("Test 1 - Value = 123456 \n");
	Itoa(value, s, 10);
	printf(""KGRN"SUCCES"KNRM" string's value = %s\n", s);
	printf("Test 2 - Value = -124 \n");
	Itoa(value2, s, 10);
	printf(""KGRN"SUCCES"KNRM" string's value = %s\n", s);

}

void TestItoa36()
{
	char buffer[33];
    int i = 0;
 
    int value[] = { 11184810, -25, 64, 127, 30};
    int base[]  = { 16, 10, 8, 2, 36};
    
    printf(""KBLU"--------TEST ITOA36--------"KNRM"\n\n");
    
    for (i = 0; i < 5; i++)
    {
        printf(""KGRN"SUCCES"KNRM" Itoa36(%d, buffer, %d) = "KGRN"%s"KNRM"\n", value[i], base[i], Itoa36(value[i], buffer, base[i]));
    }
    
}






