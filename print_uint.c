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
	int count = 0;
	unsigned int temp = num, divisor = 1, digit;

	while (temp > 9)
	{
		divisor *= 10;
		temp /= 10;
	}

	while (divisor > 0)
	{
		digit = num / divisor;
		count += print_char('0' + digit);

		num %= divisor;
		divisor /= 10;
	}

	return (count);
}
