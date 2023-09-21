#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * p_unsigned - Prints an unsigned number
 * @types: List a of arguments
 * @buf: Buffer array to handle print
 * @flages:  Calculates active flags
 * @width: get width
 * @p: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int p_unsigned(va_list types, char buf[],
	int flages, int width, int p, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int numb = va_arg(types, unsigned long int);

	numb = convert_size_unsgnd(numb, size);

	if (numb == 0)
		buf[i--] = '0';

	buf[BUFF_SIZE - 1] = '\0';

	while (numb > 0)
	{
		buf[i--] = (numb % 10) + '0';
		numb /= 10;
	}

	i++;

	return (unsign(0, i, buf, flages, width, p, size));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * octal - Prints an unsigned number in octal notation
 * @types: Lista of arguments
 * @buf: Buffer array to handle print
 * @flages:  Calculates active flags
 * @width: get width
 * @p: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int octal(va_list types, char buf[],
	int flages, int width, int p, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int numb = va_arg(types, unsigned long int);
	unsigned long int init_numb = numb;

	UNUSED(width);

	num = conv_unsgnd(numb, size);

	if (numb == 0)
		buf[i--] = '0';

	buf[BUFF_SIZE - 1] = '\0';

	while (numb > 0)
	{
		buf[i--] = (numb % 8) + '0';
		numb /= 8;
	}

	if (flages & F_HASH && init_numb != 0)
		buf[i--] = '0';

	i++;

	return (unsign(0, i, buf, flages, width, p, size));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * hexad - Prints an unsigned number in hexadecimal notation
 * @types: Lista of arguments
 * @buf: Buffer array to handle print
 * @flages:  Calculates active flags
 * @width: get width
 * @p: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int hexad(va_list types, char buf[],
	int flages, int width, int p, int size)
{
	return (hexa(types, "0123456789abcdef", buf,
		flages, 'x', width, p, size));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * hexa_up - Prints an unsigned number in upper hexadecimal notation
 * @types: Lista of arguments
 * @buf: Buffer array to handle print
 * @flages:  Calculates active flags
 * @width: get width
 * @p: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int hexa_up(va_list types, char buf[],
	int flages, int width, int p, int size)
{
	return (hexa(types, "0123456789ABCDEF", buf,
		flages, 'X', width, p, size));
}

/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * hexa - Prints a hexadecimal number in lower or upper
 * @types: Lista of arguments
 * @map_to: Array of values to map the number to
 * @buf: Buffer array to handle print
 * @flags:  Calculates active flags
 * @flag_ch: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * @size: Size specification
 * Return: Number of chars printed
 */
int hexa(va_list types, char map_to[], char buf[],
	int flages, char flag_ch, int width, int p, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int numb = va_arg(types, unsigned long int);
	unsigned long int init_numb = numb;

	UNUSED(width);

	numb = conv_unsgnd(numb, size);

	if (numb == 0)
		buf[i--] = '0';

	buf[BUFF_SIZE - 1] = '\0';

	while (numb > 0)
	{
		buf[i--] = map_to[numb % 16];
		numb /= 16;
	}

	if (flages & F_HASH && init_numb != 0)
	{
		buf[i--] = flag_ch;
		buf[i--] = '0';
	}

	i++;

	return (unsign(0, i, buf, flages, width, p, size));
}
