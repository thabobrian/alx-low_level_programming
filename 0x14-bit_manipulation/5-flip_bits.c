#include "main.h"
#include <stdio.h>

/**
 * flip_bits - returns the number of bits you would need to flip 
 * @n: the first number
 * @m: the second number
 *
 * Return: number of bits to be changed
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int j, countbit = 0;
	unsigned long int current;
	unsigned long int exclusive = n ^ m;

	for (j = 63; j >= 0; j--)
	{
		current = exclusive >> j;
		if (current & 1)
			countbit++;
	}

	return (countbit);
}
	
