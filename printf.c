#include "main.h"

/**
 * _printf - calculates the number of characters printed
 * @format:  is a character string to be printed
 *
 * Return:  the number of characters printed
 * (excluding the null byte used to end output to strings)
 */

int _printf(const char *format, ...)
{
	int i = 0, BytesNum = 0;
	va_list allargs;

	if (format == NULL)
		return (-1);
	va_start(allargs, format);
	while (*(format + i))
	{
		if (format[i] == '%')
		{
			i = i + 1;
			if (format[i] == '\0')
			{	va_end(allargs);
				return (-1); }
			if (format[i] == 'c')
				BytesNum += print_char(allargs);
			else if (format[i] == 's')
				BytesNum += print_string(allargs);
			else if (format[i] == '%')
				BytesNum += _putchar(format[i]);
			else if (format[i] == 'i' || format[i] == 'd')
				BytesNum += print_int(allargs);
			else
			{
				BytesNum += _putchar(format[--i]);
				BytesNum += _putchar(format[++i]); }}
		else
			BytesNum += _putchar(format[i]);
		i++; }
	va_end(allargs);
	return (BytesNum); }
