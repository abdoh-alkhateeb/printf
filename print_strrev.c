#include "main.h"
#include <stddef.h>

/**
 * print_strrev - a function that prints strings reversed.
 * @str: string to print.
 *
 * Return: number of characters printed, and if an
 * error is encountered, exits with status code -1;
 */
int print_strrev(char *str)
{
	int status = 0;

	if (str == NULL)
		print_str(str);

	if (*str)
	{
		status += print_strrev(str + 1);
		status += print_char(*str);
	}

	return (status);
}
