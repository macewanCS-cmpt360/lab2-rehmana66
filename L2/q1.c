#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	printf("hello world (pid:%d)\n", (int) getpid());
	int num = 100;
	int rc = fork();

	if (rc < 0) { // fork failed; exit
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if (rc == 0) { // child (new process)
		/*num = 12;
		 */
		printf("hello, I am child (pid:%d)\n", (int) getpid());
		printf("The variable num in the child process is: %d\n", num);
	} else { // parent goes down this path (main)
		num = 14;
		printf("hello, I am parent of %d (pid:%d)\n",
		rc, (int) getpid());
		printf("The variable num in the child process is: %d\n", num);
	}
	return 0;
}

	/* The value of num is 100 in the child process
	 *When you change the num value in either the parent or child,
   the num value will be set to that. However if you only set
   the num value in child to 12 then the child process will consider
   that for its new value but the parent will still consider the
   original num of 100 for being its value. This is becuase each
   process is independent of each other and run seperate until they
   are done.
	 */
