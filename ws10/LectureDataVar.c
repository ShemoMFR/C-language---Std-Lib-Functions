/******************************************************************************************
*Title: Lecture Data Variable
*Author : 
*Reviewer: 
*Description:
*Status: in developpment
*****************************************************************************************/
#include <stdio.h> /* printf */
#include <string.h> /* strchr */
#include <stdlib.h> /* strtol */

long LireLong();
void ViderBuffer();
int Lire(char *chaine, int longueur);
double LireDouble();

enum end_prog
{
	SUCCESS = 0, FAILED = 1
};

int main(void)
{
	long val = 0;
	double val2 = 0;
	
	printf("Entrez un chiffre : \n");
	val = LireLong();
	printf("%ld\n", val);
	printf("Entrez un chiffre à virgule : \n");
	val2 = LireDouble();
	printf("%lf\n", val2);
	
	return SUCCESS;

}

void ViderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}
 
int Lire(char *chaine, int longueur)
{
    char *positionEntree = NULL;
    char *point = NULL;
     
    if (NULL != fgets(chaine, longueur, stdin))
    {
        positionEntree = strchr(chaine, '\n');
        
        if (NULL != positionEntree)
        {
            *positionEntree = '\0';
        }
        
        else
        {
            ViderBuffer();
        }
        
        return 1;
    }
    else
    {
        ViderBuffer();
        return 0;
    }
}

long LireLong()
{
    char nombre_texte[100] = {0}; 
    
    if (Lire(nombre_texte, 100))
    {
        return strtol(nombre_texte, NULL, 10);
    }
    else
    {
        return 0;
    }
}

double LireDouble()
{
	char nombre_texte[100] = {0};
	char *point = NULL;
	int i = 0;
	
	if (Lire(nombre_texte, 100))
	{		
		point = strchr(nombre_texte, ',');
		
		if (NULL != point)
    	{
        	*point = '.';
    	} 
		return strtod(nombre_texte, NULL);	
	}
	else
	{
		return 0;
	}
}






















