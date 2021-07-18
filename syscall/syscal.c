/******************************************************************************************
*Title: Systems calls
*Author : 
*Reviewer: 
*Description:
*Status: in developpment
*****************************************************************************************/
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <stdio.h> /* printf */

int main(int argc, char *argv[])
{
	pid_t mypid; /* type PID */
	mypid = syscall(SYS_getpid); /* syscall(39) donne le PID processus en cours */
	
	printf("L’appel %ld donne le PID : %ld\n", (long)SYS_getpid, (long)mypid);
	
	return 0;
}
