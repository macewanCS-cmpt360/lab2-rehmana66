#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

/*
 * Not a working solution but an attempt using signals
 */

void writeup(int sig)
{
	printf("Child: hello\n");
}

void writep(int sig)
{
	printf("Parent: goodbye\n");
}

int main(int argc, char *argv[])
{
	int rc = fork();

	if (rc < 0) { // fork failed; exit
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if (rc == 0) { // child (new process)
		signal(SIGCONT, writeup);
		//printf("sds\n");
		//exit(0);
	} else { // parent goes down this path
		signal(SIGCHLD, writeup);
		//printf("sdff\n");
	}
	return 0;
}
