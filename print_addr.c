#include "main.h"
#include <stddef.h>

/**
 * print_addr - a function that prints an address.
 * @ptr: pointer that contains the address to print.
 *
 * Return: number of characters printed, and if an
 * error is encountered, exits with status code -1;
 */
unsigned int print_addr(void *ptr)
{
	unsigned int count = 0;
	unsigned long int num = (unsigned long int)ptr;
	unsigned long int temp = num, divisor = 1;
	unsigned char digit;

	if (ptr == NULL)
		return (print_str("(nil)"));

	count += print_str("0x");

	while (temp > 15)
	{
		divisor *= 16;
		temp /= 16;
	}

	while (divisor > 0)
	{
		digit = num / divisor;
		if (digit > 9)
			count += print_char('a' + digit % 9 - 1);
		else
			count += print_char('0' + digit);

		num %= divisor;
		divisor /= 16;
	}

	return (count);
}
