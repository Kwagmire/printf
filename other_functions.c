#include "main.h"

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
 * print_number - print a number
 * @num: the number
 * @base: the base to print it in
 *
 * Return: number of characters printed
 */
int print_number(unsigned int num, int base)
{
	int n = 0;

	if (num / base > 0)
		n += print_number(num / base, base);
	n += _putchar((num % base) + '0');
	return (n);
}
