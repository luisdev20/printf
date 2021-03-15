#include "holberton.h"

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

	// printf("No deseo %s muchas gracias %s", x_refresco, nombre)
	// printf("EL precio de los %s este a;o ha subido un 20%muchas gracias %s", electronico)
	if (format == NULL)
		return (-1);
	va_start(arg, format);

	/* Itera a traves del primer argumento en busca de '%' */
	while (format && *(format + i))
	{
		j = 0;
		if (format[i] == '%')
		{
		/* Itera hasta encontrar el type 'c', 's' o '%' para relacionar con
		la funcion correspondiente segun la tabla 'conversion_t' */
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
