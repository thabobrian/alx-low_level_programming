#include "main.h"
#include <stdio.h>

/**
 * _pow - func calculates (base ^ power)
 * @base: base of the exponent
 * @power: power of the exponent
 *
 * Return: value of (base ^ power)
 */
unsigned long int _pow(unsigned int base, unsigned int power)
{
	unsigned long int fig;
	unsigned int a;

	fig = 1;
	for (a = 1; a <= power; a++)
		fig *= base;
	return (fig);
}

/**
 * print_binary - function that prints the binary representation of a number
 *
 * @n: number to print
 *
 * Return: void
 */

void print_binary(unsigned long int n)
{
	unsigned long int one, two;
	char nam;

	nam = 0;
	one = _pow(2, sizeof(unsigned long int) * 8 - 1);
	while (one != 0)
	{
		two = n & one;
		if (two == one)
		{
			nam = 1;
			_putchar('1');
		}
		else if (nam == 1 || one == 1)
		{
			_putchar('0');
		}
		one >>= 1;
	}
}
