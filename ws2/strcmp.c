/*--------------------------------------------------------

WorkSheet 2 part 1 (pointers)
Developper : Moshé
Viewer : Jenia
Status : Approved

--------------------------------------------------------*/

#include <stdlib.h>
#include <stdio.h>


int StrCmp(char *s1, char *s2);

int main(void)
{
    char string1[] = "Salut";
    char string2[] = "Salut";
    int result = StrCmp(string1, string2);
    
    if (result == 0)
    {
        printf("Strings are egals!\n\n");
    }
    else if (result < 0)
    {
        printf("First string is smaller!\n\n");
    }
    else
    {
        printf("First string is biggest!\n\n");
    }
    
    
    return 0;

}

int StrCmp(char *s1, char *s2)
{
    int i = 0;

   while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'))
   {        
           
           i++;
         
   }
   
   return (s1[i] - s2[i]);
      
}
