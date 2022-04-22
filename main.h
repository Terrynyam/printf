#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
/**
 * struct print - structure for printing various types
 * @t: type to print
 * @f: function to print
 */
typedef struct print
{
	char *ts;
	int (*fs)(va_list);
} print_t;

int _putchar(char c);
int _printf(const char *format, ...);
int print_cs(va_list c);
int print_ss(va_list s);
int print_is(va_list i);
int print_ds(va_list d);
int print_us(va_list u);
int print_bs(va_list b);
int print_os(va_list o);
int print_xs(va_list x);
int print_XS(va_list X);
int print_ps(va_list p);
int print_SS(va_list S);
int print_rs(va_list r);
int print_RS(va_list R);

#endif  /* 
