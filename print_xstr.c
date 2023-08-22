#include "main.h"
#include <stddef.h>

/**
 * print_xstr - a function that prints strings (printable chars only).
 * @str: string to print.
 *
 * Return: number of characters printed, and if an
 * error is encountered, exits with status code -1;
 */
unsigned int print_xstr(char *str)
{
	unsigned int i;
	unsigned int count = 0;

	if (str == NULL)
		return (print_str(str));

	for (i = 0; str[i] != '\0'; i++)
	{
		if ((str[i] > 0 && str[i] < 32) || str[i] >= 127)
		{
			count += print_str("\\x");

			if (str[i] < 16)
				count += print_char('0');

			count += print_hex(str[i], 1);
		}
		else
			count += print_char(str[i]);
	}

	return (count);
}
