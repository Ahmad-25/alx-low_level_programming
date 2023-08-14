#include <stdio.h>
/**
 * main -entry point
 * Return: always 0(success)
 */
int main(void)
{
	int x;

	char y;

	x = 0;
	y = 'a';
	while (x <= 9)
	{
		putchar('0' + x);
		x++;
	}
	while (y <= 'f')
	{
		putchar(y);
		y++;
	}
	putchar('\n');
	return (0);
}
