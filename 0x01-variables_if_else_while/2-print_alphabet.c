#include <stdio.h>
/**
 * main - Entry point
 * Return: always 0 (success)
 */
int main(void)
{
	char X;

	X = 'a';
	while (X <= 'z')
	{
		putchar(X);
		X++;
	}
	putchar('\n');
	return (0);
}
