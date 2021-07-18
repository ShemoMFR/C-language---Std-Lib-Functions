/*--------------------------------------------------------

WorkSheet 2 part 2 (pointers)
Developper : Moshé
Viewer : Tsivia
Status : Approved

--------------------------------------------------------*/

#include <stdio.h> /*printf*/
#include <stdlib.h> /*EXIT_SUCCESS*/

void boom(int a, int b);
int CheckDigit(int a, int digit);

int main (void)
{
    boom(-10, 0);
    
    return (EXIT_SUCCESS);

}

void boom(int a, int b)
{
	int i = 0;
    
    for (i = a ; i <= b; i++)
    {
        if (i % 7 == 0 || CheckDigit(i, 7))
        {
            printf("BOOM\n");
        }
        
        else
        {
            printf("%d\n", i);
        }    
    
    }

}

int CheckDigit(int a, int digit)
{
    while (a > 0)
    {
        if (a % 10 == digit)
        {
            return 1;
        }
        a = a / 10;    
    }
    
    return 0;
    

}
