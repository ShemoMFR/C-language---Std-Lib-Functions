/*--------------------------------------------------------

WorkSheet 2 part 2 (pointers)
Developper : Moshé
Viewer : Jenia
Status : Approved

--------------------------------------------------------*/

#include <stdlib.h> /*EXIT_SUCCESS*/
#include <stdio.h>	/*PRINTF*/


void CopyArray(int *src, int *dest, size_t n);

int main(void)
{
    int array1[5] = {1, 2, 3, 4, 5};
    int array2[5]; 
    size_t size = sizeof(array1) / 4;
    size_t i = 0;
    
   	CopyArray(array1, array2, size);
   	
   	for (i = 0 ; i < size; i++)
   	{
   		printf("%d\n", array2[i]); 
   	
   	}
    
    return (EXIT_SUCCESS);  

}

void CopyArray(int *src, int *dest, size_t n)
{
 
    size_t i = 0;
        
    while (i < n)
    {
        dest[i] = src[i];
        i++;
    
    }

}
