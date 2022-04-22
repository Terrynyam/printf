#include "main.h"
#include <stdlib.h>

/**
 * print_cs - prints a char
 * @c: char to print
 *
 * Return: always 1
 */
int print_cs(va_list c)
{
	char ch = (char)va_arg(c, int);

	_putchar(ch);
	return (1);
}

/**
 * print_ss - prints a string
 * @s: string to print
 *
 * Return: number of chars printed
 */
int print_ss(va_list s)
{
	int counts;
	char *str = va_arg(s, char *);

	if (str == NULL)
		str = "(null)";
	for (counts = 0; str[counts]; counts++)
	{
		_putchar(str[counts]);
	}
	return (counts);
}

/**
 * hex_print - prints a char's ascii value in uppercase hex
 * @c: char to print
 *
 * Return: number of chars printed (always 2)
 */
static int hex_print(char c)
{
	int counts;
	char diff = 'A' - ':';
	char d[2];

	d[0] = c / 16;
	d[1] = c % 16;
	for (counts = 0; counts < 2; counts++)
	{
		if (d[counts] >= 10)
			_putchar('0' + diff + d[counts]);
		else
			_putchar('0' + d[counts]);
	}
	return (counts);
}

/**
 * print_SS - prints a string and nonprintable character ascii values
 * @S: string to print
 *
 * Return: number of chars printed
 */
int print_SS(va_list S)
{
	unsigned int i;
	int counts = 0;
	char *str = va_arg(S, char *);

	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i]; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			counts += 2;
			counts += hex_print(str[i]);
		}
		else
		{
			_putchar(str[i]);
			counts++;
		}
	}
	return (counts);
}

/**
 * print_rs - prints astring in reverse
 * @r: string to print
 *
 * Return: number of chars printed
 */
int print_rs(va_list r)
{
	char *str;
	int i, counts = 0;

	str = va_arg(r, char *);
	if (str == NULL)
		str = ")llun(";
	for (i = 0; str[i]; i++)
		;
	for (i -= 1; i >= 0; i--)
	{
		_putchar(str[i]);
		counts++;
	}
	return (counts);
}
