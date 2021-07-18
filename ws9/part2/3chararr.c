/*--------------------------------------------------------

WorkSheet 9 part 2 (Word Boundary Optimization)
Developper : Moshé
Viewer : 
Status : Dev

--------------------------------------------------------*/

#include <stdio.h>	/* printf */

void ThreeCharArr(const char *s1, const char *s2, const char *s3);
static void Test();

#define PRINT (1)
#define DONT_PRINT (2)

enum end_process
{
	SUCCESS = 0, FAILED = 1, EXIT_PROG = 2
};

int main(void)
{
	Test();
	
	return SUCCESS;
}


void ThreeCharArr(const char *s1, const char *s2, const char *s3)
{
	int LUT[255] = {0};
	unsigned char *p1 = (unsigned char *)s1;
	unsigned char *p2 = (unsigned char *)s2;
	unsigned char *p3 = (unsigned char *)s3;

	while (*p3 != '\0')
	{
		LUT[*p3] = DONT_PRINT;
		++p3;
	}

	while (*p1 != '\0')
	{
		if (LUT[*p1] != DONT_PRINT)
		{
			LUT[*p1] = PRINT;
		}
		++p1;
	}
	
	while (*p2 != '\0')
	{
		if (PRINT == LUT[*p2])
		{
			printf("%c\t", *p2);
			LUT[*p2] = DONT_PRINT;
		}
		++p2;
	}
	
	printf("\n");
}

static void Test()
{
	const char s1_1[6] = "a2349";
	const char s1_2[6] = "4987a";
	const char s1_3[6] = "14678";

	const char s2_1[7] = "abaaaa";
	const char s2_2[7] = "abcdef";
	const char s2_3[7] = "567345";

	const char s3_1[7] = "aaaaaa";
	const char s3_2[7] = "1";
	const char s3_3[7] = "a23456";

	printf("Result expected : 9 a \n");
	ThreeCharArr(s1_1, s1_2, s1_3);
	printf("Result expected : a b \n");
	ThreeCharArr(s2_1, s2_2, s2_3);
	printf("Result expected : (nothing) \n");
	ThreeCharArr(s3_1, s3_2, s3_3);
	
}



