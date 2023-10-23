#include <unistd.h>
#include "main.h"

/**
 * _puts - prints a string
 * @str: the string
 * Return: number of byte characters
 */

int _puts(const char *str)
{
	int count = 0;

	while (*str != '\0')
		count += write(1, str++, 1);
	return (count);
}
