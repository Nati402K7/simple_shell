#include "main.h"

/**
 * repalias - A function that replace_alias
 * @x: input parameter
 * Return: 1 if success, otherwith 0
 */

int repalias(data_t *x)
{
	int i;
	data_t *ia;
	char *p;

	for (i = 0; i < 10; i++)
	{
		ia = nodest(x->ali, x->as[0], '=');
		if (!ia)
			return (0);
		free(x->as[0]);
		p = _stchr(ia->sts, '=');
		if (!p)
			return (0);
		p = _stdup(p + 1);
		if (!p)
			return (0);
		x->as[0] = p;
	}
	return (1);
}

/**
 * repvar - A function that replace var
 * @x: input parameter
 * Return: 1 if success, otherwith 0
 */

int repvar(data_t *x)
{
	int i = 0;
	file_t *ia;

	for (i = 0; x->as[i]; i++)
	{
		if (x->as[i][0] != '$' || !x->as[i][1])
			continue;
		if (!_stcmp(x->as[i], "$?"))
		{
			repstr(&(x->as[i]), _stdup(convert_number(x->sts, 10 0)));
			continue;
		}
		if (!_stcmp(x->as[i], "$$"))
		{
			repstr(&(x->as[i]), _stdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		ia = nodest(x->env, &x->as[i][1], '=');
		if (ia)
		{
			repstr(&(x->as[i]), _stdup(_stchr(ia->str, '=') + 1));
			continue;
		}
		repstr(&x->as[i], _stdup(""));
	}
	return (0);
}

/**
 * repstr - A function that replace string
 * @o: old string
 * @n: new string
 * Return: 1
 */

int repstr(char **o, char **n)
{
	free(*o);
	*o = n;
	return (1);
}
