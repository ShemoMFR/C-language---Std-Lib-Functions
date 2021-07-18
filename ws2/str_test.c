/*--------------------------------------------------------

WorkSheet 2 part 2 (pointers)
Developper : Moshé
Viewer : Tsivia
Status : waiting for aproval

--------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <stddef.h>
 
#include "str.h" 

int main(void)
{
	char s1[20] = "Hello World";
	char s2[20] = "World";
	
	char s4[15] = "Coucou !";
	char s5[20] = "How are you ?";
	char s6[20] = "H ow ar";
	char s7[20] = "Hello World";
	int n = 4;
	int c = 'H';
	
	/*---------- Test Strlen----------------------------*/
	
	printf("Size expected : 11\n");
	printf("%ld\n\n", Strlen(s1));
	
	
	/*---------- Test Strcmp----------------------------*/
	
	
	printf("Result expected : Strings are egals\n");
	printf("%d\n\n", Strcmp(s1, s7));
	
	/*---------- Test Strcat----------------------------*/
	
	printf("Result expected : HelloWorld\n");
	printf("%s\n\n", StrCat(s1, s2));	
	
	/*---------- Test Strncat----------------------------*/
		
	
	printf("Result expected : Coucou !How \n");
	printf("%s\n\n", StrnCat(s4, s5, n));
	
	/*---------- Test Strspn----------------------------*/
	
	printf("Result expected : 6\n");
	printf("%ld\n\n", StrSpn(s5, s6));	
	
	/*---------- Test Strchr----------------------------*/
	
	printf("Result expected : How are you ?\n");
	printf("%s\n\n", StrChr(s5, c));	
	
	/*---------- Test Strncpy----------------------------*/
	
	printf("Result expected : How\n");
	printf("%s\n\n", StrnCpy(s4, s5, 3));
	
	/*---------- Test StrCpy----------------------------*/
	
	printf("Result expceted : World\n");
	printf("%s\n", StrCpy(s1, s2));
	
	/*---------- Test Strstr----------------------------*/
	
	printf("Result expected : World\n");
	printf("%s\n\n", StrStr(s7, s2));
	
	/*---------- Test StrDup----------------------------*/
	
	printf("Result expected : Hello World\n");
	printf("%s\n\n", StrDup(s7));
	
	/*---------- Test StrCaseCmp----------------------------*/
	
	
	
	

	return (EXIT_SUCCESS);
}
