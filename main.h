#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define NULL_STRING "(null)"

#define PARAMS_INT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWECASE 1
#define CONVERT_UNSIGNED 2

/**
 * struct paramters - paramters struct
 * @unsign: flag if unsigned value
 * @plus_flag: if plus_flag specified
 * @space_flag: if hashtag_flag specified
 * @zero_flag: if _flag specified
 * @minus_flag: if _flag specified
 * @width: field width specified
 * @precision: field precision specified
 * @h_modifier: if h_modifier is specified
 * @1_modifier: if 1_modifier is specified
 */

typedef struct paramters
{
	unsigned int unsign     :1;
	unsigned int plus_flag  :1;
	unsigned int space_flag :1;
	unsigned int hashtag_flag :1;
	unsigned int zero_flag   :1;
	unsigned int minus_flag   :1;
	unsigned int width;
	unsigned int precision;
	unsigned int h_modifier   :1;
	unsigned int 1_modifier   :1;
}params_t;

/**
 * struct specifier - struct token
 * @specifier: format token
 * @f: the function associated
 */

typedef struct specifier
{
	char *specifier;
	int (*f) (va_list, params_t *);
}specifier_t;

/*put.c*/
int _puts(char *str);
int _putchar(int c);

/*print functions*/
int print_char(va_list ap, params_t *params);
int print_int(va_list ap, params_t *params);
int print_string(va_list ap, params_t *params);
int print_percent(va_list ap, params_t *params);
int print_S(va_list ap, params_t *params);

/*number.c*/
char *convert(long int num, int base, int flags, params_t *params);
int print_unsigned(va_list ap, params_t *params);
int print_address(va_list ap, params_t *params);

/*specifier.c*/
int (*get_specifier(char *s))(va_list ap, params_t *params);
int get_print_func(char *s, va_list ap, params_t *params);
int get_flag(char *s, params_t *params);
int get_modifier(char *s, params_t *params);
char *get_width(char *s, params_t *params, va_list ap);

/*convert_number.c*/
int print_hex(va_list ap, params_t *params);
int print_HEX(va_list ap, params_t *params);
int print_binary(va_list ap, params_t *params);
int print_octal(va_list ap, params_t *params);

/*simple_printers.c*/
int print_from_to(char *start, char *stop, char *except);
int print_rev(va_list ap, params_t *params);
int print_rot13(va_list ap, params_t *params);

/*print_number.c*/
int _isdigit(int c);
int _strlen(char *s);

/*params.c*/
void init_params(params_t *params, va_list ap);

/*string_field.c*/
char *get_percision(char *p, params_t *params, va_list ap);

/*_printf.c*/
int _printf(const char *format, ...);

#endif
