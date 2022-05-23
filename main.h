#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
int _putchar(char c);
int choose_spec(char c, va_list ap, unsigned int byte);

#endif
