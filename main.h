#ifndef MY_HEADER_H
#define MY_HEADER_H
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define NULL_STRING "(null)"

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2


/* _put.c module*/
int _puts(char *str);
int _putchar(int c);

/* printf.c module*/
int _printf(const char *format, ...);
int print_int(va_list allargs, params_t *params);
int print_string(va_list allargs, params_t *params);
int print_percent(va_list allargs, params_t *params);
int print_s(va_list allargs, params_t *params);


#endif
