/*--------------------------------------------------------

WorkSheet 5 (Files)
Developper : Moshé
Viewer : 
Status : Dev

--------------------------------------------------------*/
#include <stdio.h> /* PRINTF */
#include <stdlib.h> /* EXIT_SUCCESS */

typedef struct print_me print_me;

struct print_me
{
    int a;
    void (*Print)(int);

};

void Print(int a);

int main(void)
{
       
    static size_t i = 0;
    print_me array[10] = {{1, Print}, {2, Print}, {3, Print}, {4, Print}, {5, Print}, {6, Print}, {7, Print}, {8, Print}, {9, Print}, {10, Print}};
    
    for (i = 0; i < 10; i++)
    {
    	array[i].Print(array[i].a);
    }
    
    return (EXIT_SUCCESS);

}

void Print(int a)
{
    printf("%d\n", a);

}
