#include "main.h"

/**
 * _strcat - concatenates two strings
 * @d: input value
 * @src: input value
 *
 * Return: void
 */

char *_strcat(char *d, char *src)
{
	int i;
	int j;

	i = 0;
	while (d[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (src[j] != '\0')
	{
		d[i] = src[j];
		i++;
		j++;
	}
	d[i] = '\0';
	return (d);
}

