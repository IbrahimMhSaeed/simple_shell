#include "main.h"

#define SIGHUP 1
#define SIGINT 2
#define SIGQUIT 3
#define SIGILL 4
#define SIGTRAP 5
#define SIGABRT 6

/**
 * handle_sigint - handle Ctrl + C case
 * @sig: signal number
 * Return: None
 */

void handle_sigint(int sig)
{
	(void) sig;
	write(STDOUT_FILENO, "\n", 1);
	show_prompt();

}

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

	signal(SIGINT, handle_sigint);
	if (!isatty(0))
	{
		while ((command = get_input()))
		{
			path = tokenize_path(env);
			command = clear_command(command);
			token = command_tokenization(command, path);
			if (token != NULL)
			{
				if (_strcmp(token[0], "exit") == 1)
					exit(0);
				execute(token, env, argv[0]);
			}
			free_2d(path);
		}
		return (0);
	}
	(void) argc;
	while (true)
	{
		show_prompt();
		command = get_input();
		path = tokenize_path(env);
		token = command_tokenization(command, path);
		if (token != NULL)
		{
			if (_strcmp(token[0], "exit") == 1)
				exit_0(token, path);
			execute(token, env, argv[0]);
		}
		free_2d(path);
	}
	return (0);
}
