/*--------------------------------------------------------

WorkSheet 2 part 1 (pointers)
Developper : Moshé
Viewer : Jenia
Status : Approved

--------------------------------------------------------*/

#include <stdlib.h>
#include <stdio.h> /*printf*/

void Swap(int *ptr_a, int *ptr_b);

int main(void)
{
	int a = 5;
	int b = 6;
	Swap(&a, &b);
	
	printf("Value of a = %d, value of b = %d\n", a, b);

	return (EXIT_SUCCESS);

}

void Swap(int *ptr_a, int *ptr_b)
{

	int tmp = 0;
	
	tmp = *ptr_a;
	*ptr_a = *ptr_b;
	*ptr_b = tmp;
}


