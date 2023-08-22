#include <unistd.h>
#include <stdlib.h>

/**
 * print_str - a function that prints strings.
 * @str: string to print.
 *
 * Return: number of characters printed, and if an
 * error is encountered, exits with status code -1;
 */
int print_str(char *str)
{
	size_t len;
	int status;

	if (str == NULL)
		str = "(null)";

	for (len = 0; str[len] != '\0'; len++)
		;

	status = write(1, str, len);

	if (status == -1)
		exit(-1);

	return (status);
}
