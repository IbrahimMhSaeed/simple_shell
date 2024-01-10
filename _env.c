#include "main.h"

/**
 *_env: built-in function
 *main: Entry point
 *Return: (0).
 */
extern char **environ;

void _env(void)
{
	char **env = environ;

	while (*env != NULL)
	{
	printf("%s\n", *env);
	env++;
	}
}

int main(void)
{
	_env();
	return (0);
}
