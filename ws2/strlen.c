/*--------------------------------------------------------

WorkSheet 2 part 1 (pointers)
Developper : Moshé
Viewer : Jenia
Status : Approved

--------------------------------------------------------*/

#include <stdlib.h>  /*EXIT SUCCESS */
#include <stdio.h>   /* PRINTF */
#include <assert.h>  /* ASSERT */ 

size_t Strlen(constchar *s1);

int main(void)
{

    char array[] = "Hey!";
    size_t len = 0;
    
    len = Strlen(array);
    
    printf("%d\n", len);    
    
    return (EXIT_SUCCESS);

}

size_t Strlen(constchar *s1);
{

    size_t i = 0;
            
    assert(s1 != NULL);
    
    while (s1[i] != '\0')
    {
        i++;    
    } 

    return i;

}
