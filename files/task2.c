#include "main.h"

/****************** PRINT POINTER ******************/
/**
 * print_point - Prints the value of a pointer variable
 * @types: Bring out the arguments
 * @buf: Buffer array to handle print
 * @flages:  Calculates active flags
 * @width: get width
 * @p: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_point(va_list types, char buf[],
	int flages, int width, int p, int size)
{
	char e = 0, pad = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_sta = 1; /* length=2, for '0x' */
	unsigned long num_add;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buf[BUFF_SIZE - 1] = '\0';
	UNUSED(p);

	num_add = (unsigned long)addrs;

	while (num_add > 0)
	{
		buf[ind--] = map_to[num_add % 16];
		num_add /= 16;
		length++;
	}

	if ((flages & F_ZERO) && !(flages & F_MINUS))
		pad = '0';
	if (flages & F_PLUS)
		e = '+', length++;
	else if (flages & F_SPACE)
		e = ' ', length++;

	ind++;

	/*return (write(1, &buf[i], BUFF_SIZE - i - 1));*/
	return (point(buf, ind, length,
		width, flages, pad, e, padd_sta));
}

/************************* PRINT NON PRINTABLE *************************/
/**
 * non_print - Prints ascii codes in hexa of non printable chars
 * @types: Lista of arguments
 * @buf: Buffer array to handle print
 * @flages:  Calculates active flags
 * @width: get width
 * @p: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int non_print(va_list types, char buffer[],
	int flages, int width, int p, int size)
{
	int i = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flages);
	UNUSED(width);
	UNUSED(p);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_print(str[i]))
			buf[i + offset] = str[i];
		else
			offset += hex(str[i], buf, i + offset);

		i++;
	}

	buf[i + offset] = '\0';

	return (write(1, buf, i + offset));
}

/*********************** PRINT REVERSE ***********************/
/**
 * reverse - Prints reverse string.
 * @types: Lista of arguments
 * @buf: The buffer array to handle print
 * @flages:  Calculates active flags
 * @width: get width
 * @p: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */

int reverse(va_list types, char buffer[],
	int flages, int width, int p, int size)
{
	char *str;
	int i, cnt = 0;

	UNUSED(buf);
	UNUSED(flages);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(p);

		str = "(Null)";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		cnt++;
	}
	return (cnt);
}
/************************* PRINT A STRING IN ROT13 *************************/
/**
 * rot13string - Print a string in rot13.
 * @types: Lista of arguments
 * @buf: Buffer array to handle print
 * @flages:  Calculates active flags
 * @width: get width
 * @p: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */
int rot13string(va_list types, char buf[],
	int flages, int width, int p, int size)
{
	char x;
	char *str;
	unsigned int i, k;
	int cnt = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buf);
	UNUSED(flages);
	UNUSED(width);
	UNUSED(p);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (k = 0; in[k]; k++)
		{
			if (in[k] == str[i])
			{
				x = out[k];
				write(1, &x, 1);
				cnt++;
				break;
			}
		}
		if (!in[k])
		{
			x = str[i];
			write(1, &x, 1);
			cnt++;
		}
	}
	return (cnt);
}
