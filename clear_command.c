#include "main.h"

/**
 * initialize - initialize variables
 * @start: start index var
 * @flag: flag var to set end or start
 * @i: loop var
 * Return: None
 */

void initialize(int *start, int *flag, int *i, int *j)
{
	*start = 0;
	*flag = 0;
	*i = 0;
	*j = 0;
}

/**
 * clear_command - clear command from spaces
 * @command: command to be cleared
 * Return: new command of type string or Fail (NULL)
 */

char *clear_command(char *command)
{
	int i, start, end, flag, j;
	char *newCommand;

	initialize(&start, &flag, &i, &j);
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
	if ((end - start) <= 0)
	{
		free(command);
		return (NULL);
	}
	newCommand = malloc(sizeof(char) * (end - start + 2));
	if (newCommand == NULL)
	{
		free(command);
		perror("Error: Memory allocation error");
		return (NULL);
	}
	for (i = start; i <= end; i++)
	{
		newCommand[j] = command[i];
		j++;
	}
	newCommand[j] = '\0';
	free(command);
	return (newCommand);
}
