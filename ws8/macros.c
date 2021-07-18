/*--------------------------------------------------------

WorkSheet 8 (Files)
Developper : Moshé
Viewer : Benjamin
Status : Approved

--------------------------------------------------------*/
#include <stdio.h>  /*for printf*/

#define MAX2(a, b) ((a) > (b) ? (a) : (b))
#define MAX3(a, b, c) ((MAX2(a, MAX2(b, c))))
#define SIZEOF_VAR(var) ((char *)(&var + 1) - (char *)(&var))
#define SIZEOF_TYPE(var) ((char *)(&var + 1) - (char *)(&var))

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"

int main (void)
{

	int a = 0;
	int *p = NULL;
	char c = '0';
	int result;
	int result2 = 0;
	int result3 = 0;
	int result4 = 0;
	
	struct sport 
	{
		int kravmaga;
		int karate;
		int *p;
		int football;
	} s;
		
	result = SIZEOF_VAR(a);	
	result2 = SIZEOF_VAR(p);	
	result3 = SIZEOF_VAR(c);	
	result4 = SIZEOF_TYPE(s);
	
	printf("Test MAX3 : \n");
	printf("Result expected : 31\n");
	printf("Result is : "KGRN"%d"KNRM"\n", MAX3(0, 31, 30));
	printf("Test SIZEOF_VAR : \n");
	printf("Result expected : 4, 8 and 1");
	printf("Results : "KGRN"%d, %d, %d"KNRM" ", result, result2, result3);
	printf("Test SIZEOF_TYPE : \n");
	printf("Result expected : 24 \n");
	printf("Result is : "KGRN"%d"KNRM"\n", result4);
	
	

	return 0;
}



