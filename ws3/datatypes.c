/*--------------------------------------------------------

WorkSheet 3 (pointers && Arrays)
Developper : Moshé
Viewer : Tsivia
Status : Approved

--------------------------------------------------------*/
#include <stdlib.h> /* EXIT SUCCESS */
#include <stdio.h>  /*printf */

int main(void)
{

	printf("Different type and sizes : \n\n");
	printf("Signed char : %lu bytes\n", sizeof(signed char));
	printf("Char : %ld bytes\n", sizeof(char));
    printf("Unsigned char : is %lu bytes\n", sizeof(unsigned char));
    printf("Short int : %lu bytes\n", sizeof(short int));
    printf("Signed short int : %lu bytes\n", sizeof(signed short int));
    printf("Unsigned short int : %lu bytes\n", sizeof(unsigned short int));
    printf("Unsigned int : %lu bytes\n", sizeof(unsigned int));
    printf("Int : %lu bytes\n", sizeof(int));
    printf("Float type : %lu bytes\n", sizeof(float));
    printf("Long : %lu bytes\n", sizeof(long int));
    printf("Size_t : %lu bytes\n", sizeof(size_t));
    printf("Unsigned long : %lu bytes\n", sizeof(unsigned long int)); 
    printf("Double type : %lu bytes\n", sizeof(double));
    printf("Long double : %lu bytes\n", sizeof(long double));


	return (EXIT_SUCCESS);


}
