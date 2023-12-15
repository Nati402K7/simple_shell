#include "main.h"

/**
 * hoinp - A function that hold input command
 * @x: input parameter
 * @b: buffer
 * @v: variable
 * Return: command
 */

ssize_t hoinp(data_t *x, char **b, size_t *v)
{
	ssize_t i = 0;
	size_t j = 0;

	if (!*v)
	{
		free(*b);
		*b = NULL;
		signal(SIGINT, siginHandler);
#if USE_GETLINE
		i = getline(b, &j, stdin);
#else
		i = _getline(x, b, &j);
#endif
		if (i > 0)
		{
			if ((*b)[i - 1] == '\n')
			{
				(*b)[i - 1] = '\0';
				i--;
			}
			x->li = 1;
			rcomm(*b);
			buhisl(x, *b, x->hiscou++);
			{
				*v = i;
				x->sscr = b;
			}
		}
	}
	return (i);
}

/**
 * ginp - A function that get input
 * @x: input parameter
 * Return: read input
 */

ssize_t ginp(data_t *x)
{
	static char *b;
	static size_t i, j, l;
	ssize_t r = 0;
	char **k = &(x->a), *p;

	_putchar(SCR_FLUSH);
	r = input_buf(x, &b, &l);
	if (r == -1)
		return (-1);
	if (l)
	{
		j = i;
		p = b + i;

		che_cha(x, b, &j, i, l);
		while (j < l)
		{
			if (_cha(x, b, &j))
				break;
			j++;
		}

		i = j + 1;
		if (i >= l)
		{
			i = l = 0;
			x->sscrt = SHELL_NORM;
		}

		*k = p;
		return (_stlen(p));
	}

	*k = b;
	return (r);
}

/**
 * rbuf - A function that read buffer
 * @x: input parameter
 * @b: buffer
 * @s: size of buffer
 * Return: size of readed buffer
 */

ssize_t rbuf(data_t *x, char *b, size_t *s)
{
	ssize_t i = 0;

	if (*s)
		return (0);
	i = read(x->sfd, b, SCAN_SCR_SIZE);
	if (i >= 0)
		*s = i;
	return (i);
}

/**
 * _gline - A function that get line from input
 * @x: input parameter
 * @p: pointer
 * @l: length of pointer
 * Return: geted line
 */

int _gline(data_t *x, char **p, size_t *l)
{
	static char b[SCAN_SCR_SIZE];
	static size_t i, j;
	size_t k;
	ssize_t r = 0, s = 0;
	char *q = NULL, *n = NULL, *c;

	q = *p;
	if (q && l)
		s = *l;
	if (i == j)
		i = j = 0;

	r = read_buf(x, b, &j);
	if (r == -1 || (r == 0 && j == 0))
		return (-1);

	c = _stchr(b + i, '\n');
	k = c ? 1 + (unsigned int)(c - b) : j;
	n = _reall(q, s, s ? s + k : k + 1);

	if (!n)
		return (q ? free(q), -1 : -1);

	if (s)
		_stncat(n, b + i, k - i);
	else
		_stncpy(n, b + i, k - i + 1);

	s += k - i;
	i = k;
	q = n;

	if (l)
		*l = s;
	*p = q;
	return (s);
}

/**
 * handler - A function that controls ctrol c
 * @snum: input signal number
 */

void handler(__attribute__((unused))int snum)
{
	_puts("\n");
	_puts("$ ");
	_putchar(SCR_FLUSH);
}

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

void sinf(data_t *x, char **v)
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
