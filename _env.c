#include "main.h"

/**
 *_env - Display environment variables.
 */

void _env(void)
{
	char **env = environ;

	while (*env != NULL)
	{
	printf("%s\n", *env);
	env++;
	}
}
/**
 * main - Entry point.
 * Return: 0.
 */

int main(void)
{
	_env();
	return (0);
}
