#include "main.h"

/**
 * memory_allocation_error_buffer - free memory and print error
 * @buffer: the buffer to be freed
 * Return: None
 */

void memory_allocation_error_buffer(char *buffer)
{
	perror("Error: memory allocation error");
	free(buffer);
}

/**
 * memory_allocation_error_2d - free memory from 2d array
 * @token: 2d array
 * @row: num of rows in 2d array
 * Return: None
 */

void memory_allocation_error_2d(char **token, int row)
{
	int i;

	perror("Error: memory allocation error 2D");

	for (i = 0; i < row; i++)
		free(token[i]);
	free(token);
}
