#include "main.h"

/**
 * print_int - prints integer number
 * @args: the integer to be printed
 *
 * Return: the number of printed characters
 */

int print_int(va_list args)
{
	int count = 0, digit, reverse = 0, num;
	char charDigit;

	num = va_arg(args, int);
	if (num < 0)
	{
		count += _putchar('-');
		num = -1 * num;
	}
	if (num == 0)
	{
		count += _putchar('0');
		return (count);
	}
	while (num > 0)
	{
		digit = num % 10;
		reverse = reverse * 10 + digit;
		num /= 10;
	}
	while (reverse > 0)
	{
		digit = reverse % 10;
		charDigit = '0' + digit;
		count += _putchar(charDigit);
		reverse /= 10;
	}
return (count);
}
