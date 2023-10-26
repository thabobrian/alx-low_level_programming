#include "main.h"
#include <stdio.h>

/**
 * get_bit - function that returns the value of a bit at a given index
 *
 * @index:  parameter that specifies the index of the bit i want to retrieve
 * @n: the number to check the bits
 *
 * Returns:  value of the bit at index or -1 if an error occured
 */

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int cat, dog;

	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);
	cat = 1 << index;
	dog = n & cat;
	if (dog== cat)
		return (1);
	return (0);
}
