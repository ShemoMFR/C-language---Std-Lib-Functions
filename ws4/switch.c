/*--------------------------------------------------------

WorkSheet 4
Developper : Moshé
Viewer : Jake
Status : Approved

--------------------------------------------------------*/

#include <stdio.h> /* PRINTF/SCANF*/
#include <stdlib.h> /* SYSTEM Function */

#define ESC (27)

static void DisplayLetter();

int main(void)
{	
	char letter = 0;
	
	system("stty -icanon -echo");	
	
	DisplayLetter(letter);
		
	system("stty icanon echo");
	return 0;
	
}

static void DisplayLetter()
{
	char c = 0;

	printf("Please unter A or T for display the letter. [ESCAPE] for exit\n\n");
	scanf("%c", &c);
	
	do
	{
		switch(c)
		{
			case 'A' : 
			printf("A pressed\n\n");
			break;
			case 'T' : 
			printf("T pressed\n\n");
			break;
			default : 
			printf("ERROR\n\n");
			break;
		}
		
		printf("Please unter A or T for display the letter. [ESCAPE] for exit\n\n");
		scanf("%c", &c);	
		
	} while (c != ESC);


}






