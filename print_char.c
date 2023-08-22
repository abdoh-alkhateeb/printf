#include <unistd.h>
#include <stdlib.h>

/**
 * print_char - a function that prints a chararcter.
 * @c: character to print.
 *
 * Return: 1, and if an error is encountered, exits
 * with status code -1;
 */
unsigned int print_char(char c)
{
	unsigned int count = write(1, &c, 1);

	if ((int)count == -1)
		exit(-1);

	return (count);
}
