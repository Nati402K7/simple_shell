#include "main.h"

/**
 * _setenv - A function that set an environment
 * @x: input info
 * Return: 0 if success,otherwith 1
 */

int _setenv(data_t *x)
{
	if (x->ac != 3)
	{
		_iputs("incorrect arguements of number\n");
		return (1);
	}
	if (_senv(x, x->as[1], x->as[2]))
		return (0);
	return (1);
}

/**
 * _rmenv - A function that removes an environment
 * @x: input info
 * Return: 0 if success, otherwith 1
 */

int _rmenv(data_t *x)
{
	int i;

	if (x->ac == 1)
	{
		_iputs(" arguements.\n");
		return (1);
	}
	for (i = 1; i <= x->ac; i++)
		_rmenvinf(x, x->as[i]);
	return (0);
}
