#include <stdio.h> 

int main(void)
{
	const char s1[6] = "a2349";
	const char s1[6] = "4987a";
	const char s1[6] = "14678";

	ThreeCharArr(s1, s2, s3);


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
	
	printf("%s", s3);

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
