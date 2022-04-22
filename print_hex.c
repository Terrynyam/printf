#include "main.h"

/**
 * print_hex - prints an unsigned int in hexidecimal form
 * @n: unsigned int to print
 * @c: flag to determine case of printing (0 = lower, 1 = upper)
 *
 * Return: number of digits printed
 */
int print_hex(unsigned int n, unsigned int c)
{
	unsigned int a[8];
	unsigned int j, m, total;
	char diff;
	int count;

	m = 268435456; /* (16 ^ 7) */
	if (c)
		diff = 'A' - ':';
	else
		diff = 'a' - ':';
	a[0] = n / m;
	for (j = 1; j < 8; j++)
	{
		m /= 16;
		a[j] = (n / m) % 16;
	}
	for (j = 0, total = 0, count = 0; j < 8; j++)
	{
		total += a[j];
		if (total || j == 7)
		{
			if (a[j] < 10)
				_putchar('0' + a[j]);
			else
				_putchar('0' + diff + a[j]);
			count++;
		}
	}
	return (count);
}
/**
 * print_xs - takes an unsigned int and prints it in lowercase hex notation
 * @x: unsigned int to print
 *
 * Return: number of digits printed
 */
int print_xs(va_list x)
{
	return (print_hex(va_arg(x, unsigned int), 0));
}

/**
 * print_XS - takes am unsigned int and prints it in uppercase hex notation
 * @X: unsigned int to print
 *
 * Return: number of digits printed
 */
int print_XS(va_list X)
{
	return (print_hex(va_arg(X, unsigned int), 1));
}

/**
 * _pow - calculates an exponent
 * @base: base of exponent
 * @exponent: exponent of number
 *
 * Return: base ^ exponent
 */
static unsigned long _pow(unsigned int base, unsigned int exponent)
{
	unsigned int i;
	unsigned long ans = base;

	for (i = 1; i < exponent; i++)
	{
		ans *= base;
	}
	return (ans);
}

/**
 * print_ps - prints an address
 * @p: address to print
 *
 * Return: number of characters to print
 */
int print_ps(va_list p)
{
	int count = 0;
	unsigned int a[16];
	unsigned int i, total;
	unsigned long n, m;
	char *str = "(nil)";

	n = va_arg(p, unsigned long);
	if (n == 0)
	{
		for (i = 0; str[i]; i++)
		{
			_putchar(str[i]);
			count++;
		}
		return (count);
	}
	_putchar('0');
	_putchar('x');
	count = 2;
	m = _pow(16, 15); /* 16 ^ 15 */
	a[0] = n / m;
	for (i = 1; i < 16; i++)
	{
		m /= 16;
		a[i] = (n / m) % 16;
	}
	for (i = 0, total = 0; i < 16; i++)
	{
		total += a[i];
		if (total || i == 15)
		{
			if (a[i] < 10)
				_putchar('0' + a[i]);
			else
				_putchar('0' + ('a' - ':') + a[i]);
			count++;
		}
	}
	return (count);
}
