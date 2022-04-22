#include "main.h"
#include <stdlib.h>

/**
 * check_for_specifiers - checks if there is a valid format specifier
 * @format: possible format specifier
 *
 * Return: pointer to valid function or NULL
 */
static int (*check_for_specifiers(const char *format))(va_list)
{
	unsigned int j;
	print_t p[] = {
		{"c", print_c},
		{"s", print_s},
		{"i", print_i},
		{"d", print_d},
		{"u", print_u},
		{"b", print_b},
		{"o", print_o},
		{"x", print_x},
		{"X", print_X},
		{"p", print_p},
		{"S", print_S},
		{"r", print_r},
		{"R", print_R},
		{NULL, NULL}
	};

	for (j = 0; p[j].ts != NULL; j++)
	{
		if (*(p[j].ts) == *format)
		{
			break;
		}
	}
	return (p[j].fs);
}

/**
 * _printf - prints anything
 * @format: list of argument types passed to the function
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	unsigned int j = 0, count = 0;
	va_list valist;
	int (*fs)(va_list);

	if (format == NULL)
		return (-1);
	va_start(valist, format);
	while (format[j])
	{
		for (; format[j] != '%' && format[j]; j++)
		{
			_putchar(format[j]);
			counts++;
		}
		if (!format[j])
			return (counts);
		fs = check_for_specifiers(&format[j + 1]);
		if (fs != NULL)
		{
			counts += fs(valist);
			j += 2;
			continue;
		}
		if (!format[j + 1])
			return (-1);
		_putchar(format[j]);
		counts++;
		if (format[j + 1] == '%')
			j += 2;
		else
			j++;
	}
	va_end(valist);
	return (counts);
}
