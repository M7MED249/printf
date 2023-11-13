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
		if (*format == '%' && (*(format + 1) == 'c' || *(format + 1) == 's' || *(format + 1) == '%'))
		{
			switch (*(format + 1))
			{
			case 'c':
				count += write(1, va_arg(args, int), 1);
				break;
			case 's':
				count += write(1, va_arg(args, char *), 1);
				break;
			case '%':
				count += write(1, "%", 1);
				break;
			}
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
