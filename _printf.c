#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * print_output - checks the format type
 * @specified_format: Format specifier
 * @arg: The number of arguments passed
 * Return: the number of characters
 */

int print_output(char specified_format, va_list arg)
{
	int count = 0, num;
	char c;

	if (specified_format == 'c')
	{
		c = va_arg(arg, int);
		count = _putchar(c);
	}
	else if (specified_format == 's')
	{
		count = _puts(va_arg(arg, char *));
	}
	else if (specified_format == 'd' || specified_format == 'i')
	{
		num = va_arg(arg, int);
		if (num < 0)
		{
			num = -num;
			count = print_number(num);
		}
		else if (num == 0)
		{
			count = 0;
		}
		else
		{
			count = print_number(num);
		}
	}
	else if (specified_format == '%')
	{
		count = _putchar(37);
	}
	else
		count = write(1, &specified_format, 1);
	return (count);
}

/**
 * _printf - prints formatted output
 * @format: The format output to be printed
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings)
 */

int _printf(const char *format, ...)
{
	int count = 0;

	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			count += print_output(*++format, args);
		}
		count += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (count);
}

/**
 * _puts - prints a string
 * @str: the string
 * Return: void
 */
int _puts(const char *str)
{
	int count = 0;

	while (*str != '\0')
		count += write(1, str++, 1);
	return (count);
}

/**
 * print_number - prints a number
 * @num: The number
 * Return: A number
 */
int print_number(int num)
{
	int count;

	if (num > 10)
	{
		count = _putchar((num / 10) + '0');
		return (count + _putchar((num % 10) + '0'));
	}
	return (write(1, &num, 1));
}
