#include "main.h"


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
