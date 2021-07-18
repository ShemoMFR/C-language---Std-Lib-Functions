/******************************************************************************************
*Title: Open File
*Author : 
*Reviewer: 
*Description: Error return NULL. SUCCESS return something else
*Status: in developpment
*****************************************************************************************/
#include <fcntl.h> /* functions for files */
#include <errno.h>

enum end_prog
{
	SUCCESS = 0, FAILED = 1
};

int main (int argc, char *argv[])
{
/* Ouverture en lecture du fichier
  dont on passe le chemin d’accès */
  
	int fd;
	
	fd = open(argv[1], O_WRONLY);
	
	if (fd == -1)
	{
		perror("Open ");
		return(errno);
	}

	return SUCCESS;
}


