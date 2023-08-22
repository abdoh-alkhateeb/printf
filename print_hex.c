#include "main.h"

/**
 * print_hex - a function that prints an unsigned integer in hex form.
 * @num: number to print.
 * @uppercase: can either be 1 or 0 and indicates whether the letters
 * should be printed in uppercase or not.
 *
 * Return: number of characters printed, and if an
 * error is encountered, exits with status code -1;
 */
unsigned int print_hex(unsigned int num, int uppercase)
{
	unsigned int count = 0;
	unsigned int temp = num, divisor = 1, digit;

	while (temp > 15)
	{
		divisor *= 16;
		temp /= 16;
	}

	while (divisor > 0)
	{
		digit = num / divisor;
		if (digit > 9)
			count += print_char((uppercase ? 'A' : 'a') + digit % 9 - 1);
		else
			count += print_char('0' + digit);

		num %= divisor;
		divisor /= 16;
	}

	return (count);
}
