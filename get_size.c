#include "main.h"

/**
 * get_size - Calculates the size to cast the argument
 * @s: The format string
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_size(const char *s, int *i)
{
	int curr_i = *i + 1;
	int size = 0;

	if (s[curr_i] == 'l')
		size = S_LONG;
	else if (s[curr_i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (size);
}
