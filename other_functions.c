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
/**
 * print_hexa - for hexa
 * @ap: variable list of argument
 * @c: the specifier
 *
 * Return: the number of characters printed
 */
int print_hexa(unsigned int num, char c)
{
	int n = 0;
	unsigned int j = num % 16;
	
	if (num / 16 > 0)
		n += print_hexa(num / 16, c);
	if (j > 9)
	{
		if (c == 'x')
			n += _putchar((j - 10) + 'a');
		else
			n += _putchar((j - 10) + 'A');
	}
	else
		n += _putchar((num % 16) + '0');
	
	return (n);
}
/**
 * print_Str - print a string and non printable should be in hex
 * @str: the string
 *
 * Return: the number of characters printed
 */
int print_Str(char *str)
{
	int n = 0, ascode;

	while (*str)
	{
		if (*str < 32 || *str >= 127)
		{
			n += _putchar('\\');
			n += _putchar('x');

			ascode = (int)*str;
			n += _putchar((ascode / 16) + '0');
			
			if (ascode % 16 > 9)
				n += _putchar(((ascode % 16) - 10) + 'A');
			else
				n += _putchar((ascode % 16) + '0');
		}
		else
			n += _putchar(*str);

		str++;
	}

	return (n);
}
