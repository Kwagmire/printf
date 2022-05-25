#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...);
int _putchar(char c);
int print_number(unsigned int num, int base);
int check_conversion(char c, va_list ap);
int print_char(va_list ap);
int print_str(va_list ap);
int print_int(va_list ap);
int print_bouxX(va_list ap, char c);

#endif
