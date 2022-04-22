#include "main.h"

/**
 * print_is - prints an integer
 * @i: integer to print
 *
 * Return: number of chars and digits printed
 */
int print_is(va_list i)
{
	int a[10];
	int j, m, n, total, count;

	n = va_arg(i, int);
	count = 0;
	m = 1000000000;
	a[0] = n / m;
	for (j = 1; j < 10; j++)
	{
		m /= 10;
		a[j] = (n / m) % 10;
	}
	if (n < 0)
	{
		_putchar('-');
		count++;
		for (j = 0; j < 10; j++)
			a[j] *= -1;
	}
	for (j = 0, total = 0; j < 10; j++)
	{
		total += a[j];
		if (total != 0 || j == 9)
		{
			_putchar('0' + a[j]);
			count++;
		}
	}
	return (count);
}

/**
 * print_ds - prints a decimal
 * @d: decimal to print
 *
 * Return: number of chars and digits printed
 */
int print_ds(va_list d)
{
	int a[10];
	int j, m, n, total, count;

	n = va_arg(d, int);
	count = 0;
	m = 1000000000;
	a[0] = n / m;
	for (j = 1; j < 10; j++)
	{
		m /= 10;
		a[j] = (n / m) % 10;
	}
	if (n < 0)
	{
		_putchar('-');
		count++;
		for (j = 0; j < 10; j++)
			a[j] *= -1;
	}
	for (j = 0, total = 0; j < 10; j++)
	{
		total += a[j];
		if (total != 0 || j == 9)
		{
			_putchar('0' + a[j]);
			count++;
		}
	}
	return (count);
}
