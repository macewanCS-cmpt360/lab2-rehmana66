#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

/*
 *Yes both child and parent can access the file descripter
  since they are both able to write to it. Since both the child
  and parent are writing to the file, (and since there are no wait
  indications for the parent) the parent will write first and the
  child since it is created after the parent completes its job
 */
int main(int argc, char *argv[])
{
	int file = open("./q2.txt", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
	int rc = fork();

	if (rc < 0) { // fork failed; exit
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if (rc == 0) { // child (new process)
		char *text = "I am child\n";

		write(file, text, strlen(text));
		printf("hello, I am child (pid:%d)\n", (int) getpid());
	} else {
		char *text = "I am parent\n";

		write(file, text, strlen(text));
		printf("hello, I am parent\n");
	}
	return 0;
}
