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
	int sum = 0;
	char *buffer, *str;
	va_list allargs;
	params_t params = PARAMS_INIT;

	va_start(allargs, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (buffer = (char *)format; *buffer; buffer++)
	{
		init_params(&params, allargs);
		if (*buffer != '%')
		{
			sum += _putchar(*buffer);
			continue;
		}
		str = buffer;
		buffer++;
		while (get_flag(buffer, &params))
		{
			buffer++
		}
		buffer = get_width(buffer, &params, allargs);
		buffer = get_precision(buffer, &params, allargs);
		if (get_modifier(buffer, &params))
			buffer++;
		if (!get_specifier(buffer))
			sum += print_form_to(str, buffer,
					params.1_modifier || params.h_modifier ? buffer - 1 : 0);
		else
			sum += get_print_func(buffer, allargs, &params);
	}
	_putchar(BUF_FLUSH);
	va_end(allargs);
	return (sum);
}
