#include "holberton.h"

/**
 * run_printf - Main string as input and all the necessary parameters to
 * print a formated string.
 * @format: A string containing all the desired characters.
 * @tipos: Table with format specifiers with ther respective functions.
 * @arg: Aditional arguments given to the function.
 *
 * Return: A total count of the characters printed.
 */
int run_printf(const char *format, conversion_t tipos[], va_list arg)
{
	int i = 0, j, r_val, printed_chars = 0;

	while (format[i])
	{
		if (format[i] == '%')
		{
			j = 0;
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
