#include "holberton.h"

/**
 * _strcpy - This function copies the string pointed to by src, including the
 * terminating null byte (\0), to the buffer pointed to by dest.
 * @dest: pointer to buffer point.
 * @src: pointer to string point.
 *
 * Return: returning a char.
 */
char *_strcpy(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	while (src[i] != '\0')
		i++;
	for (j = 0; j <= i; j++)
		dest[j] = src[j];
	return (dest);
}
