#include "main.h"
#include <stdio.h>

/**
 * get_endianness - function that checks the endianness
 *
 * Return: 0 if big endian, 1 if little endian
 */

int get_endianness(void)
{
	int num1;
	char *num2;

	num1 = 1;
	num2 = (char *)&num1;
	return (*num2);
}

