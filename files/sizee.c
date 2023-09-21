#include "main.h"

/**
 * sizee - Calculates the size to cast the argument
 * @fomt: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */
int sizee(const char *fomt, int *i)
{
	int cur = *i + 1;
	int siz = 0;

	if (fomt[cur] == 'l')
		siz = S_LONG;
	else if (fomt[cur] == 'h')
		siz = S_SHORT;

	if (siz == 0)
		*i = cur - 1;
	else
		*i = cur;

	return (siz);
}
