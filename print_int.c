#include "main.h"

/**
 * print_int - a function that prints an integer.
 * @num: integer to print.
 *
 * Return: number of characters printed, and if an
 * error is encountered, exits with status code -1;
 */
unsigned int print_int(int num)
{
	unsigned int count = 0;
	unsigned int temp, divisor, digit;

	if (num < 0)
	{
		count += print_char('-');
		num = -num;
	}

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
		count += print_char('0' + digit);

		num %= divisor;
		divisor /= 10;
	}

	return (count);
}
