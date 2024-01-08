#include "main.h"

/**
 * main - Entry point
 * Return: 0 always (Success)
 */

int main(void)
{
	char **token;

	while (true)
	{
		show_prompt();
		token = get_input();
		execute(token);
		break;
	}


	return (0);
}
