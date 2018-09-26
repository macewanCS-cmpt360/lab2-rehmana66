#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/*
 *The program will fork into a child and parent and run the shell
  commands on the child process while the parent waits, this will
  be in a while loop until the user decides to cancel. For background
  I created another fork if & was at the end
 */

int main(void)
{
	char *cmdline;
	char *token = NULL;
	int i, rc;
	char *args[10];
	char *s[1];

	while (1) {
		cmdline = calloc(1, 1024);
		i = 0;
		rc = fork();

		if (rc < 0) {
			fprintf(stderr, "fork failed\n");
			exit(1);
		} else if (rc == 0) {
			printf("prompt> ");
			fgets(cmdline, 1024, stdin);
			token = strtok(cmdline, "\n ");
			while (token != NULL) {
				args[i++] = strdup(token);
				token = strtok(NULL, "\n ");
			}
			args[i] = NULL;
			free(cmdline);
			if (strcmp(args[i-1], "&") == 0) {
				args[i-1] = NULL;
				int rc2 = fork();

				if (rc < 0) {
					fprintf(stderr, "fork failed\n");
					exit(1);
				} else if (rc2 == 0) {
					execvp(args[0], args);
				} else {
					int wc2 = wait(NULL);
				}
			} else {
				execvp(args[0], args);
			}
		} else {
			int wc = wait(NULL);

			sleep(1);
		}
	}
	return 0;
}

