#include "main.h"

/**
 * print_uint - a function that prints an unsigned integer.
 * @num: number to print.
 *
 * Return: number of characters printed, and if an
 * error is encountered, exits with status code -1;
 */
int print_uint(unsigned int num)
{
	int status = 0;
	unsigned int temp, divisor, digit;

	divisor = 1;
	temp = num;

	while (temp > 9)
	{
		divisor *= 10;
		temp /= 10;
	}

	while (divisor > 0)
	{
		digit = num / divisor;
		status += print_char('0' + digit);

		num %= divisor;
		divisor /= 10;
	}

	return (status);
}
