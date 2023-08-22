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
	int count;

	switch (specifier)
	{
	case 's':
		count = print_str(va_arg(*args_ptr, char *));
		break;
	case 'c':
		count = print_char(va_arg(*args_ptr, int));
		break;
	case 'i':
	case 'd':
		count = print_int(va_arg(*args_ptr, int));
		break;
	case '%':
		count = print_char('%');
		break;
	default:
		count = print_char('%');
		count += print_char(specifier);
	}

	*count_ptr += count;
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
