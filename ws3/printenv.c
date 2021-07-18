/*--------------------------------------------------------

WorkSheet 3 (pointers & Arrays)
Developper : Moshé
Viewer : Tsivia
Status : Approved

--------------------------------------------------------*/

#include <stdio.h>	/* printf */
#include <stdlib.h> /*exit success */
#include <stddef.h> /* size_t*/
#include <ctype.h> /* Tolower */
#include <string.h> /* strdup */


size_t ArrLen(char **s);
void StrToLower(char *s);
void Display(char **s);

int main(int argc, char *argv[], char *envp[])
{
  size_t i = 0;
  size_t leng = ArrLen(envp);
  char **buffer;
  (void)argc;
  (void)argv;  
    
  buffer = (char **)malloc(sizeof(char *) * (leng + 1));
  
  for (i = 0; i < leng; i++)
  {
    buffer[i] = strdup(envp[i]);   
    StrToLower(buffer[i]);
  }
    
  buffer[leng] = NULL;
  
  printf("Environment variables : \n\n");
  Display(buffer);
  
  free(buffer);
  
  return (EXIT_SUCCESS);
}

size_t ArrLen(char **s)
{
    size_t i = 0;
    
    while (*(s + i) != NULL)
    {
        ++i;        
    }
    
    return i;

}

void StrToLower(char *s)
{
    size_t i = 0;
    
    while (s[i] != '\0')
    {   
        s[i]= tolower(s[i]);    
        ++i;       
    }

}


void Display(char **s)
{
    size_t i = 0;
    
    while (s[i] != NULL)
    {
        printf("%s\n", s[i]);
        ++i;
    }


}
