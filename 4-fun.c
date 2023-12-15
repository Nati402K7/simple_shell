#include "main.h"

/**
 * _iputs - A function that prints input string
 * @s: input string
 */

void _iputs(char *s)
{
	int i = 0;

	if (!s)
		return;

	while (s[i] != '\0')
	{
		_iputchar(s[i]);
		i++;
	}
}

/**
 * _iputchar - A function that writes character to stdout
 * @c: The character to print
 * Return: 1 if success, otherwith -1
 */

int _iputchar(char c)
{
	static int i;
	static char j[LIST_SCR_SIZE];

	if (c == SCR_FLUSH || i >= LIST_SCR_SIZE)
	{
		write(2, j, i);
		i = 0;
	}
	if (c != SCR_FLUSH)
		j[i++] = c;
	return (1);
}

/**
 * _putf - A function that writes character to file
 * @c: The character to print
 * @f: filedescripter
 * Return: 1 if success, otherwith -1
 */

int _putf(char c, int f)
{
	static int i;
	static char j[LIST_SCR_SIZE];

	if (c == SCR_FLUSH || i >= LIST_SCR_SIZE)
	{
		write(f, j, i);
		i = 0;
	}
	if (c != SCR_FLUSH)
		j[i++] = c;
	return (i);
}

/**
 * _putsf - A function that prints input string of file
 * @s: input string to br printed
 * @f: filedescriptor
 * Return: number of input string
 */

int _putsf(char *s, int f)
{
	int i = 0;

	if (!s)
		return (0);
	while (*s)
	{
		i += _putf(*s++, f);
	}
	return (i);
}

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
