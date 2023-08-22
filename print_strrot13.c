#include "main.h"
#include <stddef.h>

/**
 * print_strrot13 - a function that prints strings rot13'ed.
 * @str: string to print.
 *
 * Return: number of characters printed, and if an
 * error is encountered, exits with status code -1;
 */
int print_strrot13(char *str)
{
	int i, status = 0;

	if (str == NULL)
		return (print_str(str));

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			status += print_char('a' + (str[i] - 'a' + 13) % 26);
		else if (str[i] >= 'A' && str[i] <= 'Z')
			status += print_char('A' + (str[i] - 'A' + 13) % 26);
		else
			status += print_char(str[i]);
	}

	return (status);
}
