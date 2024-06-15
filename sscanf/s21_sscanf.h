#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>
#include <stdlib.h>

#define BUF_SIZE 100

typedef struct {
    char spec;
    int width;
    int skip;
    char len;
    int res;
} Variable;

int s21_sscanf(const char *str, const char *format, ...);
const char *get_specifier(const char *ptr, Variable *v);
const char *set_value(const char *ptr, va_list parameters, Variable *v);
const char *set_signed_int(const char *ptr, va_list parameters, Variable *v, const char *hex_symb);
const char *set_unsigned_int(const char *ptr, va_list parameters, Variable *v, const char *hex_symb);