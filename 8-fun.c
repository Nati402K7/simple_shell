#include "main.h"

/**
 * _memos - A function that fill constant byte to memory
 * @s: pointer to memory
 * @b: the value to fill
 * @n: the amount to fill
 * Return: pointer to memory
 */

char *_memos(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * iact - A function that check if shell interactive
 * @x: input address
 * Return: mode
 */

int iact(data_t *x)
{
	return (isatty(STDIN_FILENO) && x->sfd <= 2);
}

/**
 * perr - A function that prints error
 * @x: parameter info
 * @e: error type string
 */

void perr(data_t *x, char *e)
{
	_iputs(x->pfn);
	_iputs(": ");
	print_d(x->ec, STDERR_FILENO);
	_iputs(": ");
	_iputs(x->as[0]);
	_iputs(": ");
	_iputs(e);
}
