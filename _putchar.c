#include "main.h"

/**
 * _putchar - print single character
 * @c: character to be printed
 * Return: 1 on Success || -1 on fail
 */

int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}
