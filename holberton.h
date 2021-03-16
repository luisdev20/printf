#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

/**
 * struct conversion - defines a structure for symbols and functions
 * @symbol: The format specifier.
 * @print: The function associated to print
 */
typedef struct conversion
{
	char *symbol;
	int (*print)(va_list arg);
} conversion_t;

int _printf(const char *format, ...);
int isnot_putchar(char c);
int print_char(va_list arg);
int print_string(va_list arg);
int print_percent(__attribute__((unused))va_list arg);
int print_integer(va_list arg);
int run_printf(const char *format, conversion_t tipos[], va_list arg);

#endif /* HOLBERTON_H */
