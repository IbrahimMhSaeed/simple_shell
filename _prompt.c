#include <string.h>
#include <sys/wait.h>
#include "main.h"

#define MAX_COMMAND 100
/**
* _prompt : prompt function
* command : a command line interpreter.
* Return : 0.
*/
void _prompt(void)
{

	printf("$ ");
	fflush(stdout);
}
int main(void)
{

	char command[MAX_COMMAND];

	while (1)
	{
	_prompt();

	if (fgets(command, MAX_COMMAND, stdin) == NULL)
	{
		break;
	}
	command[strcspn(command, "\n")] = '\0';
	pid_t pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execlp(command, command, (char *)NULL) == -1)
		{
			perror("No such file or directory");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		int status;

		if (waitpid(pid, &status, 0) == -1)
		{
			exit(EXIT_FAILURE);
		}
		if (WIFEXITED(status))
		{
		int exit_status = WEXITSTATUS(status);
		}
	}
	}
	return (0);
}
