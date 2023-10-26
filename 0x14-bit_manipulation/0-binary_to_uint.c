#include "main.h"
#include <stddef.h>

/**
 * binary_to_uint -  converts a binary number to an unsigned int
 *
 * @b: pointer
 *
 * Return: 0 if there is one or more chars in the string b that is not 0 or 1
 */

unsigned int binary_to_uint(const char *b)
{
	int a;
	unsigned int num;

	num = 0;
	if (!b)
		return (0);
	for (a = 0; b[a] != '\0'; a++)
	{
		if (b[a] != '0' && b[a] != '1')
			return (0);
	}
	for (a = 0; b[a] != '\0'; a++)
	{
		num <<= 1;
		if (b[a] == '1')
			num += 1;
	}
	return (num);
}

