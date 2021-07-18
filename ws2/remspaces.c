/*--------------------------------------------------------

WorkSheet 2 part 2 (pointers)
Developper : Moshé
Viewer : Tsivia
Status : Approved

--------------------------------------------------------*/

#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h>  /* Printf */
#include <assert.h> /* assert */

void RemSpaces(char *str);

int main (void)
{
  
    char s2[50] = "    ab      ba      ";
	char s9[50] = "     \t xe \tfg \t \t ";   
     
    RemSpaces(s2);
    RemSpaces(s9);
    
    printf("%s\n", s2);      
    printf("%s\n", s9);         
      
    
    return (EXIT_SUCCESS);
}

void RemSpaces(char *str)
{
    char *from = str;
    char *to   = str;
    
    assert(*str != NULL); 
    
    while (*from == ' ' || *from == '\t')
    {
      from++;
    }
 
    while ( *from != '\0') 
    {
      *to = *from;
        to++;
        from++;
        if (*from == ' ' || *from == '\t') 
        {
            *to++ = ' ';
            while (*from == ' ' || *from == '\t')
            {
                from++;
            }
        }
    }
 
    if (to != str) 
    {
        if (to[-1] == ' ')
         {
            to[-1] = '\0';
         }
         
    }
}   
         

