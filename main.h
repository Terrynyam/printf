#ifndef MAIN_H
#define MAIN_H
#include <stddef.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * struct structHandler - struct to choose the right function depending
 * on the format specifier passed to _printf()
 * @c: format specifier
 * @f: pointer to the correct printing function
 */
typedef struct printHandler
{
	char t;
	int (*f)(char *format, va_list);
} structype;


int _putchar(char c);
int _puts(char *string);
int printcharacter(char *format, va_list);
int printstring(char *format, va_list);
int (*driver(char *format))(char *format, va_list);
int _printf(char *format, ...);
int printinteger(char *format, va_list argu);
int integ(int nr);
int contadordigit(int number);
int _abs(int number);
int printpercentage(char *format, va_list argu);
int print_hexa(char *format, va_list);
int print_HEXA(char *format, va_list);
int print_octal(char *format, va_list);
int print_unsignd(char *format, va_list);

#endif

