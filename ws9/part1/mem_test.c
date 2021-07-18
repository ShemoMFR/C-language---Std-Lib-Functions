/*--------------------------------------------------------

WorkSheet 9 (Word Boundary Optimization)
Developper : Moshé
Viewer : 
Status : Dev

--------------------------------------------------------*/
#include <stdio.h> /* printf */
#include <string.h> /* memset, memcpy, memmove */
#include "mem.h"

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"

enum end_process
{
	SUCCESS = 0, FAILED = 1, EXIT_PROG = 2
};

int main() 
{

    int array[5] = {10, 20, 30, 40, 50};
    char s1[20] = "Hello";
    char s2[] = "World Yeah";
    char s3[] = "Helloaazazaaza";
    char s4[] = "123456";
     
/* -------------------- TEST Memset -------------------- */
  	printf(""KBLU"-------------------------------------"KNRM"\n");
  	printf(""KBLU"Memset TEST"KNRM"\n");
    PrintArr(array, 5);
    printf("Result : \n");
    Memset(array, 15, 20);
    PrintArr(array, 5);  
    printf(""KBLU"-------------------------------------"KNRM"\n");
  
/* -------------------- TEST Memcpy -------------------- */
	printf(""KBLU"Memcpy TEST"KNRM"\n");
	printf("Result : \n");
	Memcpy(s1, s2, 11);
	printf("%s\n", s1);
	printf("Expected : World Yeah \n");
	printf("Result expected : Hzazaaazazaaza\n");
	printf("Result : ");
	Memcpy(s3 + 1, s3 + 7, 5);
	printf("%s\n", s3); 
	printf(""KBLU"-------------------------------------"KNRM"\n");
	
/* -------------------- TEST Memmove -------------------- */
	printf(""KBLU"Memmove test :"KNRM" \n");
	Memmove(s3 + 1, s3 + 7, 5);
	printf("%s\n", s3); 
	Memmove(s4, s4 + 2, 7);
  	printf("%s\n", s4);
  	printf(""KBLU"-------------------------------------"KNRM"\n");
	    
    return SUCCESS;
}
