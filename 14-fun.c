#include "main.h"

/**
 * _genv - A function that gets environ value
 * @x: input info
 * @n: environ name
 * Return: geted values
 */

char *_genv(data_t *x, const char *n)
{
	file_t *ia = x->env;
	char *p;

	while (ia)
	{
		p = hashtack(ia->str, n);
		if (p && *p)
			return (p);
		ia = ia->next;
	}
	return (NULL);
}

/**
 * genvi - A function that get environ info
 * @x: input info
 * Return: info environ
 */

char **genvi(data_t *x)
{
	if (!x->envp || x->envc)
	{
		x->envp = arrstrings(x->env);
		x->envc = 0;
	}
	return (x->envp);
}
