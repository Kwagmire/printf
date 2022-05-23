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
 * @ap: variable list of argumnet
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

	n += print_number(t1);
	return (n);
}
