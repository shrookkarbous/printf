#ifndef MY_HEADER_H
#define MY_HEADER_H
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
int _printf(const char *format, ...);
int print_int(va_list allargs, params_t *params);
int print_string(va_list allargs, params_t *params);
int print_percent(va_list allargs, params_t *params);
int print_s(va_list allargs, params_t *params);

#endif
