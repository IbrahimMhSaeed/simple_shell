#include "main.h"

/**
 * adjust_token - add full path to the token
 * @token: token to be adjusted
 * @buffer: buffer conataining full path
 * Return: None
 */

void adjust_token(char **token, char *buffer)
{
	int i;

	i = 0;

	while (buffer[i] != '\0')
	{
		token[0][i] = buffer[i];
		i++;
	}
}

/**
 * check_if_path_exist - search command in path
 * @command: command to be searched
 * Return: 1 on success
 */

int check_if_path_exist(char *command)
{
	struct stat st;

	if (stat(command, &st) == -1)
		return (-1);
	else
		return (1);
}

/**
 * create_full_path - create full path for different commands
 * @path: path to add
 * @command: command to add
 * @buffer: buffer to store the full path in
 * Return: full path of command
 */

char *create_full_path(char *path, char *command, char *buffer)
{
	int i;
	int j;

	i = 0;
	while (path[i] != '\0')
	{
		buffer[i] = path[i];
		i++;
	}

	buffer[i] = '/';
	i++;

	j = 0;
	while (command[j] != '\0')
	{
		buffer[i] = command[j];
		i++;
		j++;
	}
	buffer[i] = '\0';

	return (buffer);
}

/**
 * add_directory_to_command - add directory to command
 * @token: command to be checked
 * @environ: global environment variable
 * Return: adjusted command
 */

char **add_directory_to_command(char **token, char **environ)
{
	int i;
	char *buffer;
	char **path;

	if (token[0][0] == '/')
		return (token);

	buffer = malloc(sizeof(char) * 100);

	if (buffer == NULL)
	{
		perror("Error: Memory allocation error");
		return (NULL);
	}

	path = tokenize_path(environ);

	i = 0;
	while (path[i] != NULL)
	{
		buffer = create_full_path(path[i], token[0], buffer);
		if (check_if_path_exist(buffer) == 1)
		{
			adjust_token(token, buffer);
			break;
		}
		i++;
	}
	free(buffer);
	return (token);
}

/**
 * command_tokenization - tokenize user command
 * @buffer: user command in string format
 * @environ: global environmental variable
 * Return: 2D array of tokenized command
 */

char **command_tokenization(char *buffer, char **environ)
{
	int words;
	char **token;

	token = NULL;

	words = num_words_in_string(buffer, ' ');
	if (words == -1)
	{
		perror("Entered an empty command");
		free(buffer);
		return (NULL);
	}

	token = allocate_2d_array(words, buffer, " ");

	token = add_directory_to_command(token, environ);

	free(buffer);
	return (token);
}
