#include "main.h"

/**
 * print_bin - a function that prints an unsigned integer in binary form.
 * @num: number to print.
 *
 * Return: number of characters printed, and if an
 * error is encountered, exits with status code -1;
 */
unsigned int print_bin(unsigned int num)
{
	unsigned int count = 0;
	unsigned int temp = num, divisor = 1, digit;

	while (temp > 1)
	{
		divisor *= 2;
		temp /= 2;
	}

	while (divisor > 0)
	{
		digit = num / divisor;
		count += print_char('0' + digit);

		num %= divisor;
		divisor /= 2;
	}

	return (count);
}
