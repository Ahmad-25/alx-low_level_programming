#include <stdio.h>
/**
 * main -entry point
 * Return: always 0(success)
 */
int main(void)
{
	int x;

	for (x = 0; x <= 9; x++)
	{
		putchar('0' +  x);
	}
	putchar('\n');
	return (0);
}
