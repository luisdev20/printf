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
	va_list arg;
	int chars_printed;
	conversion_t tipos[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_integer},
		{"i", print_integer},
		{"b", print_binary},
		{"r", print_rev},
		{"R", rot13},
		{NULL, NULL},
	};

	if (format == NULL)
		return (-1);
	va_start(arg, format);

	chars_printed = run_printf(format, tipos, arg);

	va_end(arg);

	return (chars_printed);
}
