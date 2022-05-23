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
 *
 * Return: number of characters
 */
int print_number(long num)
{
	int n = 0;

	if (num / 10 > 0)
		n += print_number(num / 10);
	n += _putchar((num % 10) + '0');
	return (n);
}
