#ifndef PRINTF_H
#define PRINTF_H

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define NULL_STRING "(null)"

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

/**
 * struct paraneters - a structure
 * @ unsign: unsigned int 
 * @ plus_flag: unsigned int 
 * @ space_flage: unsigned int 
 * @ hashtag_flage: unsigned int 
 * @ zero_flag: unsigned int 
 * @ minus_flag: unsigned int 
 * @ width: unsigned int 
 * @ precision: unsigned int 
 * @ h_modifier: unsigned int 
 * @ 1_modifier: unsigned int 
 */

typede struct parameters
{
	unsigned int unsign            : 1;
	unsigned int plus_flag         : 1;
	unsigned int space_flage       : 1;
	unsigned int hashtag_flage     : 1;
	unsigned int zero_flag         : 1;
	unsigned int minus_flag        : 1;

	unsigned int width;
	unsigned int precision;

	unsigned int h_modifier        : 1;
	unsigned int 1_modifier        : 1;
} params_t;

/**
 * struct specifier: a structure
 * @specifier: format structure
 * @f: a function
 */

typedef struct specifier 
{
	char *specifier;
	int (*f)(va_list, params_t *);
} specifier_t;

/* _put.c module*/
int _puts(char *str);
int _putchar(int c);

/* printf.c module*/
int _printf(const char *format, ...);
int print_char(va_list allargs, params_t *params);
int print_int(va_list allargs, params_t *params);
int print_string(va_list allargs, params_t *params);
int print_percent(va_list allargs, params_t *params);
int print_s(va_list allargs, params_t *params);

/* specifier.c module*/
int (*get_specifier(char *s)) (va_list allargs, params_t *params);
int get_print_func(char *s, va_list allargs, params_t *params);
int get_flag(char *s, params_t *params);
int get_modifier(char *s, params_t *params);
char *get_width(char *s, params_t *params);

/* params.c module */
void init_params(params_t *params, va_list allargs);

/*precision*/
char *get_precision(char *buffer, params_t *params, va_list allargs);

#endif
