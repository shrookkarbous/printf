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
	int i = 0, lenStr, BytesNum = 0;
	char *str, c;
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
				break;
			switch (format[i])
			{
				case 'c':
					c = va_arg(allargs, int);
					write(1, &c, 1);
					BytesNum++;
					break;
				case 's':
					str = va_arg(allargs, char*);
					lenStr = strlen(str);
					write(1, str, lenStr);
					BytesNum += lenStr;
					break;
				case '%':
					write(1, &format[i], 1);
					BytesNum++;
					break;
				default:
					return (-1); } }
		else
		{
			write(1, &format[i], 1);
			BytesNum++; }
		i++; }
	va_end(allargs);
	return (BytesNum); }
