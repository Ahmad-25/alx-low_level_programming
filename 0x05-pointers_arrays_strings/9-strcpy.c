#include "main.h"

/**
 * char *_strcpy - a function that copies the string pointed to by src
 * @t: copy to
 * @src: copy from
 * Return: string
 */

char *_strcpy(char *t, char *src)
{
	int i;
	int x;

	i = 0;
	x = 0;
	while (*(src + i) != '\0')
	{
		i++;
	}
	for ( ; x < i ; x++)
	{
		t[x] = src[x];
	}
	t[i] = '\0';
	return (t);
}
