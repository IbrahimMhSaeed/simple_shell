#include "main.h"

/**
 * clear_command - clear command from spaces
 * @command: command to be cleared
 * Return: new command of type string or Fail (NULL)
 */

char *clear_command(char *command)
{
	int i, start, end, flag, j;
	char *newCommand;

	start = 0;
	flag = 0;
	i = 0;
	while (command[i] != '\n' && command[i] != '\0')
	{
		if (flag == 0 && command[i] != ' ')
		{
			start = i;
			flag = 1;
		}
		else if (flag == 1 && command[i] != ' ')
		{
			if (command[i + 1] == ' ')
				end = i;
			else if (command[i + 1] == '\n' || command[i + 1] == '\0')
				end = i;
		}
		i++;
	}
	newCommand = malloc(sizeof(char) * (end - start + 1));

	if (newCommand == NULL)
	{
		printf("I am here\n");
		free(command);
		perror("Error: Memory allocation error");
		return (NULL);
	}

	j = 0;
	for (i = start; i <= end; i++)
	{
		newCommand[j] = command[i];
		j++;
	}
	free(command);
	return (newCommand);
}
