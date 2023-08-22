#include "main.h"
#include <stddef.h>

/**
 * print_strrev - a function that prints strings reversed.
 * @str: string to print.
 *
 * Return: number of characters printed, and if an
 * error is encountered, exits with status code -1;
 */
unsigned int print_strrev(char *str)
{
	unsigned int count = 0;

	if (str == NULL)
		return (print_str(str));

	if (*str)
	{
		count += print_strrev(str + 1);
		count += print_char(*str);
	}

	return (count);
}
