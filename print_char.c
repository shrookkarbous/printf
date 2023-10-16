#include "main.h"

/**
 * print_char - this function is used to print one char
 * @args: the character to be printed at args
 *
 * Return: number of printed characters
 */

int print_char(va_list args)
{
	char c = va_arg(args, int);

	_putchar(c);
	return (1);
}
