#include "main.h"


/**
 * _puts - A function that prints an input string
 * @s: input string
 */

void _puts(char *s)
{
	int i = 0;

	if (!s)
		return;

	while (s[i] != '\0')
	{
		_putchar(s[i]);
		i++;
	}
}

/**
 * _putchar - A function that writes the character c to stdout
 * @c: The character to print
 * Return: 1 if success, otherwith -1
 */

int _putchar(char c)
{
	static int i;
	static char j[LIST_SCR_SIZE];

	if (c == SCR_FLUSH || i >= LIST_SCR_SIZE)
	{
		write(1, j, i);
		i = 0;
	}
	if (c != SCR_FLUSH)
		j[i++] = c;
	return (1);
}
