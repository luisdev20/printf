#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

typedef struct conversion
{
	char *symbol;
	int (*print)(va_list arg);
} conversion_t;

int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list arg);
int print_string(va_list arg);
int print_percent(__attribute__((unused))va_list arg);

#endif /* HOLBERTON_H */
