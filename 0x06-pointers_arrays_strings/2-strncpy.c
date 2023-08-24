#include "main.h"

/**
* _strncpy - copy a string
* @d: input value
* @src: input value
* @n: input value
*
* Return: d
*/

char *_strncpy(char *d, char *src, int n)
{
	int j;

	j = 0;
	while (j < n && src[j] != '\0')
	{
		d[j] = src[j];
		j++;
	}
	while (j < n)
	{
		d[j] = '\0';
		j++;
	}
	return (d);
}

