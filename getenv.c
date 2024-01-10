#include "main.h"


/**
 * _strcmp - compare to strings
 * @comp1: string 1
 * @comp2: string 2
 * Return: 1 (equal strings) | -1 (not equal)
 */

int _strcmp(char *comp1, char *comp2)
{
	while (*comp1 != '\0' && *comp2 != '\0')
	{
		if (*comp1 != *comp2)
			return (-1);
		comp1++;
		comp2++;
	}

	return (1);
}

/**
 * get_name - gets name of path to be searched
 * @name: name to be searched
 * @var: environ row
 * Return: Name of var in environ
 */

char *get_name(char *name, char *var)
{
	int i;

	i = get_word_len(var, '=');
	i--;
	_strcpy(name, var, i);
	return (name);
}

/**
 * _getenv - get the required variable from environ
 * @name: name to be searched
 * @environ: global environment variable
 * Return: required variable from environ
 */

char *_getenv(char *name, char **environ)
{
	int i;
	char *word;

	i = 0;
	word = malloc(sizeof(char) * 50);
	if (word == NULL)
	{
		perror("Error: Memory allocation error");
		return (NULL);
	}

	while (environ[i] != NULL)
	{
		word = get_name(word, environ[i]);
		if (_strcmp(word, name) == 1)
			return (environ[i]);

		i++;
	}
	return (NULL);

}

/**
 * tokenize_path - Put paths in rows
 * @environ: the PATH variable
 * Return: 2D array
 */

char **tokenize_path(char **environ)
{
	char *env;
	char *envcp;
	int len, index, numPaths;
	char **pathToken;

	env = _getenv("PATH", environ);

	index = get_word_len(env, '=');
	len = get_word_len(env, '\0');
	envcp = malloc(sizeof(char) * (len - index));

	if (envcp == NULL)
		perror("Error: Memory allocation error");
	_strcpy(envcp, &env[index], len);

	numPaths = num_words_in_string(envcp, ':');

	pathToken = allocate_2d_array(numPaths, envcp, ":");

	return (pathToken);
}
