#include "main.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

/**
 * print_char - print a character
 * @ap: variable list of argument
 *
 * Return: 1
 */
int print_char(va_list ap)
{
	return (_putchar(va_arg(ap, int)));
}
/**
 * print_str - print a string
 * @ap: variable list of argument
 *
 * Return: number of characters printed
 */
int print_str(va_list ap)
{
	int n  = 0;
	char *t0 = va_arg(ap, char *);

	if (t0 == NULL)
		t0 = "(null)";
	while (*t0)
	{
		n += _putchar(*t0);
		t0++;
	}

	return (n);
}
/**
 * print_int - print an integer
 * @ap: variable list of argument
 *
 * Return: number of characters printed
 */
int print_int(va_list ap)
{
	int n = 0;
	long t1 = (long)va_arg(ap, int);

	if (t1 < 0)
	{
		_putchar('-');
		n++;
		t1 *= -1;
	}

	n += print_number((unsigned int)t1, 10);
	return (n);
}
/**
 * print_bouxX - for binary, octal and uint
 * @ap: variable list of argument
 * @c: the specifier
 *
 * Return: number of characters printed
 */
int print_bouxX(va_list ap, char c)
{
	int n = 0;
	unsigned int t2 = va_arg(ap, unsigned int);

	if (c == 'b')
		n += print_number(t2, 2);
	else if (c == 'u')
		n += print_number(t2, 10);
	else if (c == 'o')
		n += print_number(t2, 8);
	else if (c == 'x' || c == 'X')
		n += print_hexa(t2, c);

	return (n);
}
