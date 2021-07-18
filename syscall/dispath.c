/******************************************************************************************
*Title: Display Path of file
*Author : 
*Reviewer: 
*Description: Error return NULL. SUCCESS return something else
*Status: in developpment
*****************************************************************************************/
#include <libgen.h> /* basename, dirname */
#include <stdio.h> /* printf + perror */
#include <errno.h> /* errno */


enum end_prog
{
	SUCCESS = 0, FAILED = 1
};
/* Ce programme affiche séparément les répertoires d’accès
	et le nom du chemin d’accès passé en argument */

int main(int argc, char * argv[])
{
	char *buff;
	
	if (argc < 2)
	{
		printf("%s: Syntaxe : base-dir CheminFichier\n",argv[0]);
		return FAILED;
	}
/* Répertoires d’accès au fichier */
	buff = dirname(argv[1]);
	
	if (buff != NULL)
	{
		printf("Chemin d’accès hors nom de fichier : %s\n", buff);
	}
	else
	{
		perror("Chemin incorrect:");
		return errno;
	}
/* Nom du fichier */

	buff = basename(argv[1]);
	if (buff != NULL)
	{
		printf("Nom du fichier : %s\n", buff);
	}
	else
	{
		perror("Chemin incorrect:");
		return errno;
	}
	
		return SUCCESS;
}




