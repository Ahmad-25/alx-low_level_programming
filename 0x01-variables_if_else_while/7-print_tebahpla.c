#include <stdio.h>
/**
 * main -entrypoint
 * Return: always 0(success)
 */
int main(void)
{
	int y;

	for (y = 'z'; y >= 'a'; y--)
	{
		putchar(y);
	}
	putchar('\n');
	return (0);
}
