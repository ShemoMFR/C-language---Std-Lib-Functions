/*--------------------------------------------------------

WorkSheet 8 (Files)
Developper : Moshé
Viewer : Benjamin
Status : Dev

--------------------------------------------------------*/
#include <stdio.h> /* printf */
#include <stdlib.h> /* malloc */
#include <string.h> /* strcat/strcpy */
#include "struct_arr.h"

int main(void)
{

	generic_type_t arr[6];
		
	InitInt(&arr[0], 7);
	InitInt(&arr[1], 15);
	InitFloat(&arr[2], 1.5);
	InitInt(&arr[3], 15);
	InitChar(&arr[4], "Hello");
	InitChar(&arr[5], "World");	
	
	/*--------------------------- Test Part ---------------------------------------*/
	
	Print(arr, 6); 
	printf("\n-----------------------------------------\n\n");
	AddInt(&arr[1], 10); 
	AddFloat(&arr[2], 2);
	AddChar(&arr[4], 10);
	Add(arr, 10, 6);
	Print(arr, 6);
	Clean(arr, 6);
	
	  

	return 0; 
}


