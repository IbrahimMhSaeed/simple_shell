#include "main.h"

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

	/**
	 * if (argc > 1)
	 * {
	 * command = argv[1];
	 * token = command_tokenization(command);
	 * execute_arg(token);
	 * }
	 */

	path = tokenize_path(env);

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
				exit(-1);
			execute(token, env);
		}
	}


	return (0);
}
