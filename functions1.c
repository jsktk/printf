#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned - Prints unsigned interger numbers
 * @ap: Argument pointer
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size
 * Return: Number of characters printed.
 */

int print_unsigned(va_list ap, char buffer[],
	int flags, int width, int precision, int size)
{
	int b = BUFF_SIZE - 2;
	unsigned long int num = va_arg(ap, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[b--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[b--] = (num % 10) + '0';
		num /= 10;
	}

	b++;

	return (write_unsgnd(0, b, buffer, flags, width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_octal - Prints unsigned number in octal notation
 * @ap: Argument pointer
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size
 * Return: Number of chars printed
 */
int print_octal(va_list ap, char buffer[],
	int flags, int width, int precision, int size)
{

	int b = BUFF_SIZE - 2;
	unsigned long int num = va_arg(ap, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[b--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[b--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[b--] = '0';

	b++;

	return (write_unsgnd(0, b, buffer, flags, width, precision, size));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexadecimal - Prints unsigned number in hexadecimal notation
 * @ap: Argument pointer
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size
 * Return: Number of chars printed
 */
int print_hexadecimal(va_list ap, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(ap, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_hexa_upper - Prints unsigned number in upper hexadecimal
 * @ap: Argument pointer
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size
 * Return: Number of chars printed
 */
int print_hexa_upper(va_list ap, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(ap, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * print_hexa - Prints  hexadecimal number in lower or upper
 * @ap: Argument pointer
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @flag_ch: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size
 * @size: Size specification
 * Return: Number of chars printed
 */
int print_hexa(va_list ap, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int b = BUFF_SIZE - 2;
	unsigned long int num = va_arg(ap, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[b--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[b--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[b--] = flag_ch;
		buffer[b--] = '0';
	}

	b++;

	return (write_unsgnd(0, b, buffer, flags, width, precision, size));
}
