/*--------------------------------------------------------

WorkSheet 2 part 2 (pointers)
Developper : Moshé
Viewer : Tsivia
Status : Approved

--------------------------------------------------------*/

#include <stdlib.h> /* EXIT SUCCESS*/ 
#include <stdio.h>  /* printf*/ 
#include <string.h> /*strlen*/

int IsaPalindrome(char *str);

int main(void)
{
    char array[] = "Hannah";
    int result = 0;
    
    result = IsaPalindrome(array);
    
    
    if (result == 1)
    {
        printf("This is a palindrome!\n\n");
    }
    else
    {
        printf("Its not a palindrome!\n\n");
    }
    
    return (EXIT_SUCCESS);

}

int IsaPalindrome(char *str)
{
    int leng = 0;
    int SmallLeng = 0;
    int count = 0;
    int i = 0;
    
    leng = strlen(str);
    SmallLeng = (leng / 2) + 1;
    
    for (i = 0; i < SmallLeng; i++)
    {
        if (str[i] == str[leng - i -1])
        {
            count++;
        }
    }
    if (count == SmallLeng)
    {
        return 1;
    }
    else
    {
        return 0;
        
}

}
