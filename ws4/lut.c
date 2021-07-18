/*--------------------------------------------------------

WorkSheet 4
Developper : Moshé
Viewer : Jake
Status : Approved

--------------------------------------------------------*/

#include <stdio.h> /* PRINTF/SCANF*/
#include <stdlib.h> /* SYSTEM Function */

static void Lut();
static int DisplayA();
static int DisplayT();
static int Empty();


int main(void)
{           
    system("stty -icanon -echo");
        
    Lut();
    
    system("stty icanon echo");
    return 0;
    
}

static void Lut()
{
 	int (*array[256])() = { Empty };
    unsigned char letter = 0;	
	
	array[65] = DisplayA;
    array[84] = DisplayT;
    
    
    printf("Please unter A or T for display the letter. [ESCAPE] for exit\n\n");
    scanf("%c", &letter);
    
    array[letter]();

	do
    {
     	printf("Please unter A or T for display the letter. [ESCAPE] for exit\n\n");
    	scanf("%c", &letter);
    } while (array[letter]() == 1);

}

static int DisplayA()
{
    printf("A Pressed\n\n");
    return 1;

}
static int DisplayT()
{
    printf("T pressed\n\n");
    return 1;

}
static int Empty()
{
	return 1;
}








