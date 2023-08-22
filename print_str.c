#include <unistd.h>
#include <stdlib.h>

/**
 * print_str - a function that prints strings.
 * @str: string to print.
 *
 * Return: number of characters printed, and if an
 * error is encountered, exits with status code -1;
 */
unsigned int print_str(char *str)
{
	unsigned int len;
	unsigned int count;

	if (str == NULL)
		str = "(null)";

	for (len = 0; str[len] != '\0'; len++)
		;

	count = write(1, str, len);

	if ((int)count == -1)
		exit(-1);

	return (count);
}
