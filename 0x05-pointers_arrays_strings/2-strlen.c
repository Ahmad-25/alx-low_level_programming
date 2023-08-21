#include "main.h"

/**
 * _strlen - returns the lenght of a string
 * @s: string
 * Return: length
 */

int _strlen(char *s)
{
	int y = 0;

	while (*s != '\0')
	{
		y++;
		s++;
	}
	return (y);
}
