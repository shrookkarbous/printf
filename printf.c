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
			switch (format[i])
			{
				case 'c':
					BytesNum += print_char(allargs);
					break;
				case 's':
					BytesNum += print_string(allargs);
					break;
				case '%':
					BytesNum += _putchar(format[i]);
					break;
				case 'i':
					BytesNum += print_int(allargs);
					break;
				case 'd':
					BytesNum += print_int(allargs);
					break;
				default:
					BytesNum += _putchar(format[--i]);
					BytesNum += _putchar(format[++i]); }}
		else
		{
			BytesNum += _putchar(format[i]); }
		i++; }
	va_end(allargs);
	return (BytesNum); }
