#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @s: The format string
 * @i: List of arguments to be printed.
 * @ap: Arguments pointer
 *
 * Return: Precision.
 */
int get_precision(const char *s, int *i, va_list ap)
{
	int curr_i = *i + 1;
	int precision = -1;

	if (s[curr_i] != '.')
		return (precision);

	precision = 0;

for (curr_i += 1; s[curr_i] != '\0'; curr_i++)
{
	if (is_digit(s[curr_i]))
	{
		precision *= 10;
		precision += s[curr_i] - '0';
	}
	else if (s[curr_i] == '*')
	{
	curr_i++;
	precision = va_arg(ap, int);
		break;
	}
	else
		break;
	}

	*i = curr_i - 1;

	return (precision);
}
