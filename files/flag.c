#include "main.h"

/**
 * flagss - Get active flags
 * @fomt: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flages:
 */
int flagss(const char *fomt, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int k, cur;
	int flages = 0;
	const char FLAGES_CHE[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (cur = *i + 1; fomt[cur] != '\0'; cur++)
	{
		for (k = 0; FLAGES_CHE[j] != '\0'; k++)
			if (fomt[cur] == FLAGES_CHE[k])
			{
				flages |= FLAGES_ARR[k];
				break;
			}

		if (FLAGES_CHE[k] == 0)
			break;
	}

	*i = cur - 1;

	return (flages);
}
