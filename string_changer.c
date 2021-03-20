#include "holberton.h"

/**
 * print_S - Converts an argument to a string.
 * @arg: A va_list pointing to the argument to be converted.
 * Return: The number of bytes stored to the buffer.
 *
 * Description: Non-printable characteres (ASCII values < 32 or >= 127)
 *              are stored as \x followed by the ASCII code value in hex.
 */
int print_S(va_list arg)
{
        char *string, *hex = "0123456789ABCDEF";
	int i = 0;

        string = va_arg(arg, char*);

        if (string == NULL)
                string = "(null)";

        for (i = 0; string[i] != '\0'; i++)
	{
		if (string[i] < 32 || string[i] >= 127)
		{
			isnot_putchar('\\');
			isnot_putchar('x');

			if (string[i] < 16)
				isnot_putchar('0');
			isnot_putchar(hex[i + 1]);

			continue;
		}

		isnot_putchar(string[i]);
	}
        return (i);
}

