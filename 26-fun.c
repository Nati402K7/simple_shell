#include "main.h"


/**
 * pralias - A function that prints alias
 * @ia: input alias
 * Return: 0 or 1
 */

int pralias(data_t *ia)
{
	char *p = NULL, *a = NULL;

	if (ia)
	{
		p = _stchr(ia->sts, '=');
		for (a = ia->sts; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _alias - A function that prints man alias
 * @x: input parameter
 * Return: 0
 */

int _alias(data_t *x)
{
	int i = 0;
	char *p = NULL;
	file_t *ia = NULL;

	if (x->ac == 1)
	{
		ia = x->ali;
		while (ia)
		{
			pralias(ia);
			ia = ia->next;
		}
		return (0);
	}
	for (i = 1; x->as[i]; i++)
	{
		p = _stchr(x->as[i], '=');
		if (p)
			salias(x, x->as[i]);
		else
			pralias(nodest(x->ali, x->as[i], '='));
	}
	return (0);
}
