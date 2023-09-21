#include "main.h"

/**
 * width - Calculates the width for printing
 * @frmt: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int width(const char *fomt, int *i, va_list list)
{
	int cur;
	int width = 0;

	for (cur = *i + 1; format[cur] != '\0'; cur++)
	{
		if (digitt(format[cur]))
		{
			width *= 10;
			width += fomt[cur] - '0';
		}
		else if (fomt[cur] == '*')
		{
			cur++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = cur - 1;

	return (width);
}
