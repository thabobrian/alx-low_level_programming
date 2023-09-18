#include "main.h"
/**
 * _puts- function name
 * @str: function parameter
 */

void _puts(char *str)
{
	int i;

	for (i = 0; str[1] != '\0'; i++)
		_putchar (str[i]);
	_putchar ('\n');
}

