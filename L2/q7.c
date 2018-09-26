#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

/*
 *In this case when you close STDOUT and printf nothing
  will print because the stdout that printf uses it closed
  and therefore cannot output the text
 */

int main(int argc, char *argv[])
{
	int rc = fork();

	if (rc < 0) {
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if (rc == 0) {
		close(STDOUT_FILENO);
		printf("Hello I am child\n");
	} else {
		printf("hello, I am parent\n");
	}
	return 0;
}
