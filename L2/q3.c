#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

/*
 * Not a working solution but an attempt using signals
 */
		
int main(int argc, char *argv[])
{
	int rc = fork();

	if (rc < 0) { // fork failed; exit
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if (rc == 0) { // child (new process)
		printf("Child: hello\n");
	} else { // parent goes down this path
		sleep(1);
		printf("Parent: goodbye\n");
	}
	return 0;
}
