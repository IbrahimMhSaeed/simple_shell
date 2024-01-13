#include "main.h"

/**
 * _env - print environment
 * @env: global environment variable
 * Return: None
 */

void _env(char **env)
{
	int i, j;


	i = 0;
	while (env[i] != NULL)
	{
		printf("\n\n%s\n", env[i]);
		j = 0;
		while (env[i][j] != '\0')
		{
			_putchar(env[i][j]);
			j++;
		}
		_putchar('\n');
		i++;
	}
}
