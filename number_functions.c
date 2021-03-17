#include "holberton.h"

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

/**
 * print_binary - Converts a number from base 10 to binary
 * @arg: List of arguments passed to this function
 * Return: The length of the number printed
 */
int print_binary(va_list arg)
{
	unsigned int num;
	int i, len;
	char *str;
	char *rev_str;

	num = va_arg(arg, unsigned int);
	if (num == 0)
		return (isnot_putchar('0'));
	if (num < 1)
		return (-1);
	len = base_len(num, 2);
	str = malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (-1);

	for (i = 0; num > 0; i++)
	{
		if (num % 2 == 0)
			str[i] = '0';
		else
			str[i] = '1';
		num = num / 2;
	}
	str[i] = '\0';
	rev_str = rev_string(str);
	if (rev_str == NULL)
		return (-1);
	write_base(rev_str);
	free(str);
	free(rev_str);
	return (len);
}
