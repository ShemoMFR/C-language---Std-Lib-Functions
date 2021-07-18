/*--------------------------------------------------------

WorkSheet 9 part 2(Word Boundary Optimization)
Developper : Moshé
Viewer : 
Status : Dev

--------------------------------------------------------*/
#include <stdio.h>

int x = 1;
#define IS_LITTLE_ENDIAN ((char *)(1) == (char *)(1u) ? (1) : (0))

void IsLittleEndian();

int main(void)
{
	IS_LITTLE_ENDIAN;
	
	IsLittleEndian();
	
	return 0;
}

void IsLittleEndian()
{
   short s = 1;
   char *c = (char *)&s;
   
   if (*c)
   {
   		printf("Little Endian\n");
   }
   else
   {
   		printf("Big Endian\n");
   }
  
}
