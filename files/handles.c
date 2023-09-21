#include "main.h"
/**
 * handle - Prints an argument based on its type
 * @fot: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @ind: ind.
 * @buf: Buffer array to handle print.
 * @flags: Calculates active flags
 * @width: get width.
 * @p: Precision specification
 * @size: specifies size
 * Return: 1 or 2;
 */

int handle(const char *fot, int *ind, va_list list, char buf[],
		int flags, int width, int p, int size)
{
int i, unknow_len = 0, printed_chars = -1;
	fot_t fot_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (i = 0; fot_types[i].fot != '\0' i++)
		if (fot[*ind] == fot_types[i].fot)
			return (fot_types[i].fn(list, buf, flags, width, p, size));

	if (fot_types[i].fot == '\0')
	{
		if (fot[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (fot[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fot[*ind] != ' ' && fot[*ind] != '%')
				--(*ind);
			if (fot[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &fot[*ind], 1);
		return (unknow_len);
	}
	return (printed_chars);
}
