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
	int i, j, k, lenStr, BytesNum = 0,  lenFormat = strlen(format);
	char *buffer, *str;
	va_list allargs;

	if (format == NULL)
		return (-1);
	va_start(allargs, format);
	buffer = (char *)malloc(lenFormat + 1);
	if (buffer == NULL)
		exit(98);
	i = 0;
	k = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i = i + 1;
			switch (format[i])
			{
				case 'c':
					buffer[k] = va_arg(allargs, int);
					k++;
					break;
				case 's':
					str	 = va_arg(allargs, char*);
					lenStr = strlen(str);
					for (j = k; j < (lenStr + k); j++)
					{
						buffer[k] = str[j - k];
						k++; }
					break;
				case '%':
					buffer[k] = va_arg(allargs, int);
					k++;
					break; } } }
	va_end(allargs);
	BytesNum = write(1, buffer, strlen(buffer));
	return (BytesNum); }
