#include "holberton.h"

/**
 * print_octal - Prints the numeric representation of a number in octal base
 * @arg: List of all the arguments passed to the program
 * Return: Number of symbols printed to stdout
 */
int print_octal(va_list arg)
{
	unsigned int num;
	int len;
	char *octal_rev;
	char *octal;

	num = va_arg(arg, unsigned int);

	if (num == 0)
		return (isnot_putchar('0'));
	if (num < 1)
		return (-1);
	len = base_len(num, 8);

	octal_rev = malloc(sizeof(char) * len + 1);
	if (octal_rev == NULL)
		return (-1);
	for (len = 0; num > 0; len++)
	{
		octal_rev[len] = (num % 8) + 48;
		num = num / 8;

	}
	octal_rev[len] = '\0';
	octal = rev_string(octal_rev);
	if (octal == NULL)
		return (-1);

	write_base(octal);
	free(octal_rev);
	free(octal);
	return (len);
}

/**
 * hex_check - Checks which hex function is calling it
 * @num: Number to convert into char
 * @x: Tells which hex function is calling it
 * Return: Ascii value for a letter
 */
int hex_check(int num, char x)
{
	char *hex = "abcdef";
	char *Hex = "ABCDEF";

	num = num - 10;
	if (x == 'x')
		return (hex[num]);
	else
		return (Hex[num]);
	return (0);
}

/**
 * print_hex - Prints a representation of a decimal number on base16 lowercase
 * @arg: List of the arguments passed to the function
 * Return: Number of characters printed
 */
int print_hex(va_list arg)
{
	unsigned int num;
	int len, rem_num;
	char *hex_rev, *hex;

	num = va_arg(arg, unsigned int);

	if (num == 0)
		return (isnot_putchar('0'));
	if (num < 1)
		return (-1);
	len = base_len(num, 16);
	hex_rev = malloc(sizeof(char) * len + 1);
	if (hex_rev == NULL)
		return (-1);
	for (len = 0; num > 0; len++)
	{
		rem_num = num % 16;
		if (rem_num > 9)
		{
			rem_num = hex_check(rem_num, 'x');
			hex_rev[len] = rem_num;
		}
		else
			hex_rev[len] = rem_num + 48;
		num = num / 16;
	}
	hex_rev[len] = '\0';
	hex = rev_string(hex_rev);
	if (hex == NULL)
		return (-1);
	write_base(hex);
	free(hex_rev);
	free(hex);
	return (len);
}

/**
 * print_HEX - Prints a representation of a decimal number on base16 lowercase
 * @arg: List of the arguments passed to the function
 * Return: Number of characters printed
 */
int print_HEX(va_list arg)
{
	unsigned int num;
	int len, rem_num;
	char *hex_rev, *hex;

	num = va_arg(arg, unsigned int);

	if (num == 0)
		return (isnot_putchar('0'));
	if (num < 1)
		return (-1);
	len = base_len(num, 16);
	hex_rev = malloc(sizeof(char) * len + 1);
	if (hex_rev == NULL)
		return (-1);
	for (len = 0; num > 0; len++)
	{
		rem_num = num % 16;
		if (rem_num > 9)
		{
			rem_num = hex_check(rem_num, 'X');
			hex_rev[len] = rem_num;
		}
		else
			hex_rev[len] = rem_num + 48;
		num = num / 16;
	}
	hex_rev[len] = '\0';
	hex = rev_string(hex_rev);
	if (hex == NULL)
		return (-1);
	write_base(hex);
	free(hex_rev);
	free(hex);
	return (len);
}
