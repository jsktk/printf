#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @s: The format string
 * @i: List of arguments to be printed
 * @ap: Argument pointer
 *
 * Return: width.
 */
int get_width(const char *s, int *i, va_list ap)
{
	int curr_i;
	int width = 0;

	for (curr_i = *i + 1; s[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(s[curr_i]))
		{
			width *= 10;
			width += s[curr_i] - '0';
		}
		else if (s[curr_i] == '*')
		{
			curr_i++;
			width = va_arg(ap, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (width);
}
