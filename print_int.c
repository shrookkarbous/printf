#include "main.h"

/**
 * print_int - prints integer number
 * @num: the integer to be printed
 *
 * Return: the number of printed characters
 */

int print_int(int num)
{
	int count = 0;

	if (num < 0)
	{
		count += _putchar('-');
		num = -1 * num;
	}
	if (num >= 0)
	{
		print_int(num / 10);
	}
	count += _putchar('0' + (num % 10));
	return (count);
}
