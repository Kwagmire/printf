#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

/**
 * _putchar - print to standard output
 * @c: what to print
 *
 * Return: 0 or -1
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * choose_spec - perform specific commands
 *		 based on the specifier
 * @c: the specifier
 * @ap: the variable argument list
 * @byte: the number of bytes printed before the function
 *
 * Return: the number of bytes printed after the function runs
 */
int choose_spec(char c, va_list ap, unsigned int byte)
{
	char *t0;

	if (c == 'c')
	{
		_putchar(va_arg(ap, int));
		byte++;
	}
	else if (c == 's')
	{
		t0 = va_arg(ap, char *);
		if (t0 == NULL)
			t0 = "(null)";
		while (*t0)
		{
			_putchar(*t0);
			byte++;
			t0++;
		}
	}
	else if (c == '%')
	{
		_putchar('%');
		byte++;
	}
	else
	{
		_putchar('%');
		_putchar(c);
		byte += 2;
	}

	return (byte);
}
/**
 * _printf - print formatted output
 * @format: the format
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	unsigned int byte = 0, i = 0;
	va_list ap;

	if (format == NULL)
		return (-1);

	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] != '\0')
			{
				byte = choose_spec(format[i + 1], ap, byte);
				i += 2;
			}
			else
			{
				va_end(ap);
				return (byte);
			}
		}
		else
		{
			_putchar(format[i]);
			i++;
			byte++;
		}
	}
	va_end(ap);

	return (byte);
}
