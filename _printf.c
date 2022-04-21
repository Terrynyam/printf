#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: format string containing the characters and the specifiers
 * Return: length of the formatted output string
 */

int _printf(const char *format, ...)
{
	int count = 0, (*thefunctn)(char *, va_list);
	const char t[3];
	va_list argu;

	if (format == NULL)
		return (-1);
	t[2] = '\0';
	va_start(argu, format);
	_putchar(-1);
	while (format[0])
	{
		if (format[0] == '%')
		{
			structype = driver(format);
			if (structype)
			{
				t[0] = '%';
				t[1] = format[1];
				count += structype(t, argu);
			}
			else if (format[1] != '\0')
			{
				count += _putchar('%');
				count += _putchar(format[1]);
			}
			else
			{
				count += _putchar('%');
				break;
			}
			format += 2;
		}
		else
		{
			count += _putchar(format[0]);
			format++;
		}
	}
	_putchar(-2);
	return (count);
}
