#include "main.h"

/**
 * _printf - a function that produces output according to a format.
 * @format: pointer to a string
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings)
 */

int _printf(const char *format, ...)
{	va_list args;
	va_start(args, format);

	int count = 0, i; /*keep the tracking on the number of Characters*/

	for (int i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{	i++; /*move past '%'*/

			if (format[i] == 'c')
			{	int c = va_arg(args, int);

				putchar(c);
				count++; }
			else if (format[i] == 's')
			{	char *s = va_arg(args, char *);

				while (*s != '\0')
				{
					putchar(*s);
					s++;
					count++; }
			}
			else if (format[i] == '%')
			{	putchar('%');
				count++; }
		}
		else
		{	putchar(format[i]);
			count++; }
	}
	va_end(args);
	return (count);
}
