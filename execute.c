#include "main.h"

/**
 * test_token - test the aquired input
 * @token: tokenized user input
 * Return: None
 */

void test_token(char **token)
{
	int i;

	i = 0;
	while (token[i] != NULL)
	{
		printf("%s\n", token[i]);
		i++;
	}

}


/**
 * execute - execute user command
 * @token: user input tokenization
 * @env: environmental variable
 * Return: 0 always (Success)
 */

int execute(char **token, char **env)
{
	int status;
	pid_t child;
	struct stat st;

	if (stat(token[0], &st) == -1)
	{
		free_2d(token);
		perror("Error");
		return (-1);
	}

	child = fork();

	if (child == -1)
	{
		free_2d(token);
		perror("Error");
		return (-1);
	} else if (child == 0)
		execve(token[0], token, env);
	else
	{
		wait(&status);
		free_2d(token);
	}
	return (0);
}
