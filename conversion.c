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

	if (string == NULL)
		string = "(null)";

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

/**
 * print_integer - Function to print integers.
 * @arg: Aditional arguments given to the function.
 *
 * Return: A total count of the characters printed.
 */
int print_integer(va_list arg)
{
	int n, digit_count = 1, len = 0;
	unsigned int num, div = 1;

	n = va_arg(arg, int);

	if (n < 0)
	{
		isnot_putchar('-');
		num = n * (-1);
		len++;
	}
	else
		num = n;

	while (div <= num / 10)
	{
		digit_count++;
		div = div * 10;
	}

	while (digit_count > 0)
	{
		isnot_putchar('0' + num / div);
		num = num % div;
		div = div / 10;
		digit_count--;
		len++;
	}

	return (len);
}


int rot13(va_list list)
{
        int i;
        int x;
        char *str;
        char s[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        char u[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

        str = va_arg(list, char *);
        if (str == NULL)
                return (-1);
        for (i = 0; str[i] != '\0'; i++)
        {
                for (x = 0; x <= 52; x++)
                {
                        if (str[i] == s[x])
                        {
                                isnot_putchar(u[x]);
                                break;
                        }
                }
                if (x == 53)
                        isnot_putchar(str[i]);
        }
        return (i);
}

/**
 * print_rev - Calls a function to reverse and print a string
 * @arg: Argument passed to the function
 * Return: The amount of characters printed
 */
int print_rev(va_list arg)
{
	int len;
	char *str;
	char *ptr;

	str = va_arg(arg, char *);
	if (str == NULL)
		return (-1);
	ptr = rev_string(str);
	if (ptr == NULL)
		return (-1);
	for (len = 0; ptr[len] != '\0'; len++)
		isnot_putchar(ptr[len]);
	free(ptr);
	return (len);
}
