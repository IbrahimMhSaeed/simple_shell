#include "main.h"

/**
 * empty_command - check if command is all spaces
 * @buffer: command to be checked
 * Return: 1 if command is valid || -1 if command not valid
 */

int empty_command(char *buffer)
{
	int i;

	i = 0;
	while (buffer[i] != '\n')
	{
		if (buffer[i] != 32)
			return (1);
		i++;
	}
	return (-1);
}


/**
 * exit_0 - exit shell
 * @token: tokenized command to be freed
 * @path: free path
 * Return: None
 */

void exit_0(char **token, char **path)
{
	free_2d(path);
	free_2d(token);
	exit(0);
}
