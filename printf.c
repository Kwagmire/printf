#include "main.h"

/**
 * check_conversion - perform specific commands
 *		      based on the specifier
 * @c: the specifier
 * @ap: the variable argument list
 *
 * Return: the number of bytes printed
 */
int check_conversion(char c, va_list ap)
{
	int n = 0;

	if (c == 'c')
		n += print_char(ap);
	else if (c == 's')
		n += print_str(ap);
	else if (c == '%')
		n += _putchar('%');
	else if (c == 'd' || c == 'i')
		n += print_int(ap);
	else
	{
		_putchar('%');
		_putchar(c);
		n += 2;
	}
	return (n);
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
				byte += check_conversion(format[i + 1], ap);
				i += 2;
			}
			else
			{
				va_end(ap);
				return (-1);
			}
		}
		else
		{
			byte += _putchar(format[i]);
			i++;
		}
	}
	va_end(ap);

	return (byte);
}
int main(void)
{
	int m;
	
	m = _printf("Let's print a simple sentence.\n");
	_printf("%d\n", m);
	m = printf("Let's print a simple sentence.\n");
	printf("%d\n", m);
	m = _printf("%c", 'S');
	_printf("%d\n", m);
	m = printf("%c", 'S');
	printf("%d\n", m);
	m = _printf("A char inside a sentence: %c. Did it work?\n", 'F');
	_printf("%d\n", m);
	m = printf("A char inside a sentence: %c. Did it work?\n", 'F');
	printf("%d\n", m);
	m = _printf("Let'see if the cast is correctly done: %c. Did it work?\n", 48);
	_printf("%d\n", m);
	m = printf("Let'see if the cast is correctly done: %c. Did it work?\n", 48);
	printf("%d\n", m);
	m = _printf("%s", "This sentence is retrieved from va_args!\n");
	_printf("%d\n", m);
	m = printf("%s", "This sentence is retrieved from va_args!\n");
	printf("%d\n", m);
	m = _printf("Complete the sentence: You %s nothing, Jon Snow.\n", "know");
	_printf("%d\n", m);
	m = printf("Complete the sentence: You %s nothing, Jon Snow.\n", "know");
	printf("%d\n", m);
	m = _printf("Complete the sentence: You %s nothing, Jon Snow.\n", (char *)0);
	_printf("%d\n", m);
	m = printf("Complete the sentence: You %s nothing, Jon Snow.\n", (char *)0);
	printf("%d\n", m);
	m = _printf("%c%cth %s%s a%cg%s: Y%sou %s no%ching%s Snow.%c", 'W', 'i', "some ", "more", 'r', "s", "", "know", 't', ", Jon", '\n');
	_printf("%d\n", m);
	m = printf("%c%cth %s%s a%cg%s: Y%sou %s no%ching%s Snow.%c", 'W', 'i', "some ", "more", 'r', "s", "", "know", 't', ", Jon", '\n');
	printf("%d\n", m);
	m = _printf("%%");
	_printf("%d\n", m);
	m = printf("%%");
	printf("%d\n", m);
	m = _printf("Should print a single percent sign: %%\n");
	_printf("%d\n", m);
	m = printf("Should print a single percent sign: %%\n");
	printf("%d\n", m);
	m = _printf("%s%c%c%c%s%%%s%c", "Loading ", '.', '.', '.', " 99", " Please wait", '\n');
	_printf("%d\n", m);
	m = printf("%s%c%c%c%s%%%s%c", "Loading ", '.', '.', '.', " 99", " Please wait", '\n');
	printf("%d\n", m);
	m = _printf("css%ccs%scscscs", 'T', "Test");
	_printf("%d\n", m);
	m = printf("css%ccs%scscscs", 'T', "Test");
	printf("%d\n", m);
	m = _printf(NULL);
	_printf("%d\n", m);
	m = printf(NULL);
	printf("%d\n", m);
	m = _printf("%c", '\0');
	_printf("%d\n", m);
	m = printf("%c", '\0');
	printf("%d\n", m);
	m = _printf("%");
	_printf("%d\n", m);
	m = printf("%");
	printf("%d\n", m);
	m = _printf("%!\n");
	_printf("%d\n", m);
	m = printf("%!\n");
	printf("%d\n", m);
	m = _printf("%K\n");
	_printf("%d\n", m);
	m = printf("%K\n");
	printf("%d\n", m);
	
	return (0);
}
