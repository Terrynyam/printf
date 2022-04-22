#include "main.h"

/**
 * print_us - prints an unsigned in in decimal notation
 * @u: unsigned int to print
 *
 * Return: number of digits printed
 */
int print_us(va_list u)
{
	unsigned int a[10];
	unsigned int i, m, n, total;
	int count;

	n = va_arg(u, unsigned int);
	m = 1000000000; /* (10 ^ 9) */
	a[0] = n / m;
	for (i = 1; i < 10; i++)
	{
		m /= 10;
		a[i] = (n / m) % 10;
	}
	for (i = 0, total = 0, count = 0; i < 10; i++)
	{
		total += a[i];
		if (total || i == 9)
		{
			_putchar('0' + a[i]);
			count++;
		}
	}
	return (count);
}

/**
 * print_os - takes an unsigned int and prints it in octal notation
 * @o: unsigned int to print
 *
 * Return: number of digits printed
 */
int print_o(va_list o)
{
	unsigned int a[11];
	unsigned int i, m, n, total;
	int count;

	n = va_arg(o, unsigned int);
	m = 1073741824; /* (8 ^ 10) */
	a[0] = n / m;
	for (i = 1; i < 11; i++)
	{
		m /= 8;
		a[i] = (n / m) % 8;
	}
	for (i = 0, total = 0, count = 0; i < 11; i++)
	{
		total += a[i];
		if (total || i == 10)
		{
			_putchar('0' + a[i]);
			count++;
		}
	}
	return (count);
}

/**
 * print_bs - takes an unsigned int and prints it in binary notation
 * @b: unsigned in to print
 *
 * Return: number of digits printed
 */
int print_bs(va_list b)
{
	unsigned int n, m, i, total;
	unsigned int a[32];
	int count;

	n = va_arg(b, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, total = 0, count = 0; i < 32; i++)
	{
		total += a[i];
		if (total || i == 31)
		{
			_putchar('0' + a[i]);
			count++;
		}
	}
	return (count);
}
