#include "main.h"

/**
 * show_prompt - print prompt to the screen
 * Return: 0 Always (Success)
 */

void show_prompt(void)
{
	if (write(STDOUT_FILENO, "alxsimple@alxsimple-Ubuntu20.4:~ $ ", 35) == -1)
	{
		perror("Couldn't show prompt!");
		exit(-1);
	}

}
