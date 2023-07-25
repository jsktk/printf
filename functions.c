#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * print_char - Prints character
 * @ap: Argument pointer
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size
 * Return: Number of chars printed
 */
int print_char(va_list ap, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(ap, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}
/************************* PRINT A STRING *************************/
/**
 * print_string - Prints string
 * @ap: Argument pointer
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width.
 * @precision: Precision specification
 * @size: Size
 * Return: Number of chars printed
 */
int print_string(va_list ap, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, j;
	char *str = va_arg(ap, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (j = width - length; j > 0; j--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (j = width - length; j > 0; j--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}
/************************* PRINT PERCENT SIGN *************************/
/**
 * print_percent - Prints percent sign
 * @ap: Argument pointer
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width.
 * @precision: Precision specification
 * @size: Size
 * Return: Number of chars printed
 */
int print_percent(va_list ap, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/************************* PRINT INT *************************/
/**
 * print_int - Print intger
 * @ap: Argument pointer
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width.
 * @precision: Precision specification
 * @size: Size
 * Return: Number of chars printed
 */
int print_int(va_list ap, char buffer[],
	int flags, int width, int precision, int size)
{
	int j = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(ap, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[j--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[j--] = (num % 10) + '0';
		num /= 10;
	}

	j++;

	return (write_number(is_negative, j, buffer, flags, width, precision, size));
}

/******************** PRINT BINARY ***********************/
/**
 * print_binary - Prints unsigned number
 * @ap: Argument pointer
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size
 * Return: Numbers of char printed.
 */
int print_binary(va_list ap, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int k, l, j, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	k = va_arg(ap, unsigned int);
	l = 2147483648; /* (2 ^ 31) */
	a[0] = k / l;
	for (j = 1; j < 32; j++)
	{
		l /= 2;
		a[j] = (k / l) % 2;
	}
	for (j = 0, sum = 0, count = 0; j < 32; j++)
	{
		sum += a[j];
		if (sum || j == 31)
		{
			char z = '0' + a[j];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
