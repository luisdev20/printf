#include "holberton.h"

int print_char(va_list arg)
{
	char letter;

	letter = va_arg(arg, int);
	_putchar(letter);
	return (1);
}

int print_string(va_list arg)
{
	char *string;
	int i = 0;

	string = va_arg(arg, char*);

	while (string[i])
	{
		_putchar(string[i]);
		i++;
	}
	return (i);
}

int print_percent(__attribute__((unused))va_list arg)
{
	_putchar('%');
	return(1);
}
