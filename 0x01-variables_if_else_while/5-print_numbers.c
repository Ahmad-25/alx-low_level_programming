#include <stdio.h>
/**
 * main -Entry point
 * Return: always 0(successs)
 */
int main(void)
{
	int x;

	x = 0;

	while (x <= 9)
	{
		printf("%d", x);
		x++;
	}
	putchar('\n');
	return (0);
}
