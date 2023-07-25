#include "main.h"

/**
 * get_flags - Calculates active flag function
 * @s: Format string
 * @p: take a parameter.
 * Return: Flags
 */

int get_flags(const char *s, int *p)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, curr_p;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_p = *p + 1; s[curr_p] != '\0'; curr_p++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (s[curr_p] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*p = curr_p - 1;

	return (flags);
}
