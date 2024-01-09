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

	/*
	if (argc > 1)
	{
		command = argv[1];
		token = command_tokenization(command);
		execute_arg(token);
	}
	*/

	(void) argc;
	(void) argv;

	while (true)
	{
		show_prompt();
		command = get_input();
		token = command_tokenization(command, env);
		if (token != NULL)
			execute(token, env);
	}


	return (0);
}
