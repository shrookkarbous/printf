#include "main.h"

/**
 * print_int - prints integer number
 * @args: the integer to be printed
 *
 * Return: the number of printed characters
 */

int print_int(va_list args)
{
	int count = 0, num, numDigits = 0, temp, i, digit, divisor;

	num = va_arg(args, int);
	if (num == 0)
		return (_putchar('0'));
	if (num < 0)
	{
		count += _putchar('-');
		num = -num; }
	temp = num;
	while (temp > 0)
	{
		temp /= 10;
		numDigits++; }
	while (numDigits > 0)
	{
		divisor = 1;
		for (i = 1; i < numDigits; i++)
			divisor *= 10;
		digit = num / divisor;
		count += _putchar('0' + digit);
		num %= divisor;
		numDigits--; }
	return (count);
}
