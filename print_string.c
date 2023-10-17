#include "main.h"

/**
 * print_string - prints string
 * @args: the string to be printed at passes args
 *
 * Return: the string length
 */

int print_string(va_list args)
{
	char *str;
	int StrLen, i;

	str = va_arg(args, char *);
	if (str == NULL)
	{
		str = "(null)";
		StrLen = strlen(str);
	}
	else
	{
StrLen = strlen(str);
	}
	for (i = 0; i < StrLen; i++)
		_putchar(str[i]);
	return (StrLen);
}
