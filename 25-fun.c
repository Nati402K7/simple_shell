#include "main.h"

/**
 * clearer - A function that clear info
 * @x: input address
 */

void clearer(data_t *x)
{
	x->a = NULL;
	x->as = NULL;
	x->p = NULL;
	x->ac = 0;
}

/**
 * sinf - A function that set info
 * @x: input address
 * @v: vector
 */

void sinfo(data_t *x, char **v)
{
	int i = 0;

	x->pfn = v[0];
	if (x->a)
	{
		x->as = stspl(x->a, " \t");
		if (!x->as)
		{
			x->as = malloc(sizeof(char *) * 2);
			if (x->as)
			{
				x->as[0] = _stdup(x->a);
				x->as[1] = NULL;
			}
		}
		for (i = 0; x->as && x->as[i]; i++)
			;
		x->ac = i;

		repalias(x);
		repvar(x);
	}
}

/**
 * finf - A function that free info
 * @x: input address
 * @i: input field
 */

void finf(data_t *x, int i)
{
	fstr(x->as);
	x->as = NULL;
	x->p = NULL;
	if (i)
	{
		if (!x->sscr)
			free(x->a);
		if (x->env)
			freenode(&(x->env));
		if (x->htr)
			freenode(&(x->htr));
		if (x->ali)
			freenode(&(x->ali));
		fstr(x->envp);
		x->envp = NULL;
		fadd((void **)x->sscr);
		if (x->sfd > 2)
			close(x->sfd);
		_putchar(SCR_FLUSH);
	}
}
