#include "main.h"

/**
 * print_bin - a function that prints an unsigned integer in binary form.
 * @num: number to print.
 *
 * Return: number of characters printed, and if an
 * error is encountered, exits with status code -1;
 */
int print_bin(unsigned int num)
{
	int status = 0;
	unsigned int temp, divisor, digit;

	divisor = 1;
	temp = num;

	while (temp > 1)
	{
		divisor *= 2;
		temp /= 2;
	}

	while (divisor > 0)
	{
		digit = num / divisor;
		status += print_char('0' + digit);

		num %= divisor;
		divisor /= 2;
	}

	return (status);
}
