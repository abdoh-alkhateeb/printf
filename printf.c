#include <stddef.h>
#include <stdarg.h>
#include "main.h"

/**
 * handle_specifier - a function that calls the appropriate function
 * for a specifier and handle associated logic.
 * @specifier: character that will be checked.
 * @args_ptr: pointer to the arguments list.
 * @count_ptr: pointer to the characters printed count variable.
 *
 * Return: nothing.
 */
void handle_specifier(char specifier, va_list *args_ptr, int *count_ptr)
{
	switch (specifier)
	{
	case 's':
		*count_ptr += print_str(va_arg(*args_ptr, char *));
		break;
	case 'r':
		*count_ptr += print_strrev(va_arg(*args_ptr, char *));
		break;
	case 'R':
		*count_ptr += print_strrot13(va_arg(*args_ptr, char *));
		break;
	case 'c':
		*count_ptr += print_char(va_arg(*args_ptr, int));
		break;
	case 'i':
	case 'd':
		*count_ptr += print_int(va_arg(*args_ptr, int));
		break;
	case 'u':
		*count_ptr += print_uint(va_arg(*args_ptr, unsigned int));
		break;
	case 'b':
		*count_ptr += print_bin(va_arg(*args_ptr, unsigned int));
		break;
	case 'o':
		*count_ptr += print_oct(va_arg(*args_ptr, unsigned int));
		break;
	case 'x':
		*count_ptr += print_hex(va_arg(*args_ptr, unsigned int), 0);
		break;
	case 'X':
		*count_ptr += print_hex(va_arg(*args_ptr, unsigned int), 1);
		break;
	case '%':
		*count_ptr += print_char('%');
		break;
	default:
		*count_ptr += print_char('%');
		*count_ptr += print_char(specifier);
	}
}

/**
 * _printf - a function that produces output according to a format.
 * @format: a character string that is composed of zero or more directives.
 *
 * Return: number of characters printed.
 * (excluding the null byte used to end output to strings).
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			handle_specifier(*format, &args, &count);
		}
		else
			count += print_char(*format);

		format++;
	}
	va_end(args);
	return (count);
}
