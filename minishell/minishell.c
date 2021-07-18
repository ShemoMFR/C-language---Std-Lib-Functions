/******************************************************************************************
*Title: Display Path of file
*Author : 
*Reviewer: 
*Description: Error return NULL. SUCCESS return something else
*Status: in developpment
*****************************************************************************************/
#include <stdio.h> /* printf */
#include <stdlib.h> /* strcmp */
#include <string.h> /* strlen */

#define TAILLE_BUFFER 150

int main (int argc, char *argv[])
{
	char buffer[TAILLE_BUFFER];
	
	printf("---------- MINI SHELL ---------\n");
	
	while (1)
    {
        printf("Prompt : ");
        fgets(buffer, 150, stdin);
        buffer[strlen(buffer) - 1] = '\0';
        
        if (0 == strcmp("exit", buffer))
        {
            exit(0);
        }
        
        if (0 == strcmp("ls -l", buffer))
        {
        	system(buffer);
        }
        else
        {
        	printf("%s\n", buffer);
        	system(buffer);
        }
    }	

	return 0;
}

