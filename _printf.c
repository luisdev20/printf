#include "holberton.h"

/**
 * _printf - Main string as input and all the necessary parameters to
 * print a formated string.
 * @format: A string containing all the desired characters.
 *
 * Return: A total count of the characters printed.
 */
int _printf(const char *format, ...)
{
	int i = 0, j, r_val, printed_chars = 0;
	va_list arg;
	conversion_t tipos[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{NULL, NULL},
	};

	if (format == NULL)
		return (-1);
	va_start(arg, format);
	while (*(format + i))
	{
		j = 0;
		if (format[i] == '%')
		{
			while (tipos[j].symbol != NULL)
			{
				if (format[i + 1] == *tipos[j].symbol)
				{
					r_val = tipos[j].print(arg);
					if (r_val == -1)
						return (-1);
					printed_chars += r_val;
					break;
				}
				j++;
			}
			if (tipos[j].symbol == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					_putchar(format[i]);
					_putchar(format[i + 1]);
					printed_chars += 2;
				}
				else
					return (-1);
			}
			i++;
		}
		else
		{
			_putchar(format[i]);
			printed_chars++;
		}
		i++;
	}
	return (printed_chars);
}
