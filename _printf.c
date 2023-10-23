#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - prints formatted output
 * @format: The format output to be printed
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings)
 */

int _printf(const char *format, ...)
{
	int count = 0, n;
	va_list args;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			switch (*(format + 1))
			{
				case 'c':
					count = _putchar(va_arg(args, int));
					++format;
					break;
				case 's':
					count = _puts(va_arg(args, char *));
					++format;
					break;
				case 'd':
				case 'i':
					n = va_arg(args, int);
					if (n < 0)
					{
						count = _putchar('-');
						n = -n;
					}
					count += print_number(n);
					++format;
					break;
				case '%':
					count = _putchar(37);
					break;
			}
		}
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (count);
}

/**
 * print_number - prints a number
 * @n: The number
 * Return: A number
 */
int print_number(int n)
{
	int count;

	count = 0;

	if (n >= 10)
	{
		count += print_number(n / 10);
	}
	count += _putchar((n % 10) + '0');
	return (count);
}
