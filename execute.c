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
 * Return: 0 always (Success)
 */

int execute(char **token)
{

	/**
	 * handle Error cases
	 */

	int status;
	pid_t child;
	struct stat st;

	/**
	 * char *argv[] = {"/bin/ls", "-l", "tmp", NULL};
	 */

	/*
	 * test for input format
	 * printf("token->\n");
	 * test_token(token);
	 * printf("argv -> \n");
	 * test_token(argv);
	 */

	if (stat(token[0], &st) == -1)
	{
		perror("Error");
		return (-1);
	}

	child = fork();

	if (child == -1)
	{
		perror("Error");
		return (-1);
	} else if (child == 0)
		execve(token[0], token, NULL);
	else
	{
		wait(&status);
	}
	return (0);
}
