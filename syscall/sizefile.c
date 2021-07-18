/******************************************************************************************
*Title: Size file
*Author : 
*Reviewer: 
*Description: Sys call return 0 if success, -1 if failed.
*Status: in developpment
*****************************************************************************************/
#include <sys/types.h> /* Define type off_t qui est un long */
#include <sys/stat.h> /* Sys Call stat */
#include <unistd.h> 
#include <errno.h> /* errno */
#include <stdio.h> /* printf */

enum end_prog
{
	SUCCESS = 0, FAILED = 1
};

int main (int argc, char *argv[])
{
	int coderet;
	struct stat infos;
	
	if (argc < 2)
	{
		fprintf(stderr,"%s:%s CheminFichier\n",argv[0],argv[0]); /* écrit dans le flux erreur le nom du fichier au cas où on envoie aucun argument a argv */
		return 1;
	}
/* Appel système pour obtenir les informations du fichier */
	coderet = stat(argv[1], &infos);
	
	if (!coderet)
	{
	
/* La taille du fichier en octets
est dans l’élément st_size */
		printf("Size of file %s = %ld bytes\n", argv[0], infos.st_size);
	}	
	else
	{
	/* Erreur */
		coderet = errno;
		perror(argv[0]);
	}
	
	return coderet;
}




