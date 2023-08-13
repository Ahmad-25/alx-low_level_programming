#include <stdio.h>
/**
 * main -Entry point
 * Return: always 0 (success)
 */
int main(void)
{
	int x;

	for (x = 'a'; x <= 'z'; x++)
	{
		if ((x == 'e') || (x == 'q'))
		{
			continue;
		}
		putchar(x);
	}
	putchar('\n');
	return (0);
}
