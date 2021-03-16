#include "holberton.h"

/**
 * print_char - Function to print chars.
 * @arg: Aditional arguments given to the function.
 *
 * Return: A total count of the characters printed.
 */
int print_char(va_list arg)
{
	char letter;

	letter = va_arg(arg, int);
	isnot_putchar(letter);
	return (1);
}

/**
 * print_string - Function to print strings.
 * @arg: Aditional arguments given to the function.
 *
 * Return: A total count of the characters printed.
 */
int print_string(va_list arg)
{
	char *string;
	int i = 0;

	string = va_arg(arg, char*);

	while (string[i])
	{
		isnot_putchar(string[i]);
		i++;
	}
	return (i);
}

/**
 * print_percent - Function to print percent symbols.
 * @arg: Aditional arguments given to the function.
 *
 * Return: A total count of the characters printed.
 */
int print_percent(__attribute__((unused))va_list arg)
{
	isnot_putchar('%');
	return (1);
}
