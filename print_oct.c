#include "main.h"

/**
 * print_oct - a function that prints an unsigned integer in octet form.
 * @num: number to print.
 *
 * Return: number of characters printed, and if an
 * error is encountered, exits with status code -1;
 */
int print_oct(unsigned int num)
{
	int status = 0;
	unsigned int temp, divisor, digit;

	divisor = 1;
	temp = num;

	while (temp > 7)
	{
		divisor *= 8;
		temp /= 8;
	}

	while (divisor > 0)
	{
		digit = num / divisor;
		status += print_char('0' + digit);

		num %= divisor;
		divisor /= 8;
	}

	return (status);
}
