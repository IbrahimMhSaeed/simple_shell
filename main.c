#include "main.h"

#define SIGHUP 1
#define SIGINT 2
#define SIGQUIT 3
#define SIGILL 4
#define SIGTRAP 5
#define SIGABRT 6

/**
 * main - Entry point
 * @argc: argument c
 * @argv: argument v
 * @env: global environment variable
 * Return: 0 always (Success)
 */

int main(int argc, char *argv[], char **env)
{
	char *command;
	char **token;
	char **path;

	path = tokenize_path(env);
	if (!isatty(0))
	{
		while ((command = get_input()))
		{
			command = clear_command(command);
			token = command_tokenization(command, path);
			if (token != NULL)
			{
				if (_strcmp(token[0], "exit") == 1)
					exit(0);
				execute(token, env);
			}
		}
		free_2d(path);
		return (0);
	}
	(void) argc;
	(void) argv;
	while (true)
	{
		show_prompt();
		command = get_input();
		token = command_tokenization(command, path);
		if (token != NULL)
		{
			if (_strcmp(token[0], "exit") == 1)
				exit(0);
			execute(token, env);
		}
	}
	free_2d(path);
	return (0);
}
