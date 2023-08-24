#include "main.h"
/**
 * _strncat - concatenate two strings
 * using at most n bytes from src
 * @d: input value
 * @src: input value
 * @n: input value
 *
 * Return: d
 */

char *_strncat(char *d, char *src, int n)
{
	int i;
	int j;

	i = 0;
	while (d[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (j < n && src[j] != '\0')
	{
		d[i] = src[j];
		i++;
		j++;
	}
	d[i] = '\0';
	return (d);
}
