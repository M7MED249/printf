#include "main.h"
#include "holberton.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Produces output according to a format.
 * @format: The format string.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	if (format == NULL)
		return -1;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%' && (*(format + 1) == 'd' || *(format + 1) == 'i'))
		{
			count += _print_number(va_arg(args, int));
			format += 2;
		}
		else
		{
			count += write(1, format, 1);
			format++;
		}
	}

	va_end(args);

	return count;
}

/**
 * _print_number - Prints an integer.
 * @n: The integer to print.
 *
 * Return: The number of characters printed.
 */
int _print_number(int n)
{
	int count = 0;

	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}

	if (n / 10)
		count += _print_number(n / 10);

	count += write(1, &((char)('0' + n % 10)), 1);

	return count;
}
