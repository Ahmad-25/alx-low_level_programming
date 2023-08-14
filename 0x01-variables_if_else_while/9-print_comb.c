#include <stdio.h>
/**
 * main -entry point
 * Return: always 0 (success)
 */
int main(void)
{
	int num;

	for (num = 0; num <= 9; num++)
	{
		putchar('0' + num);
		putchar(',');
		putchar(' ');
	}
	putchar('\n');
	return (0);
}
