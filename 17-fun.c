#include "main.h"

/**
 * _lihis - A function that list history
 * @x: input parameter
 * Return: 0
 */

int _lihis(data_t *x)
{
	prlist(x->htr);
	return (0);
}

/**
 * gethis - A function that gets history file
 * @x: input parameter
 * Return: history file
 */

char *gethis(data_t *x)
{
	char *b, *d;

	d = _genv(x, "HOME=");
	if (!d)
		return (NULL);
	b = malloc(sizeof(char) * (_stlen(d) + _stlen(HIT_DOC) + 2));
	if (!b)
		return (NULL);
	b[0] = 0;
	_stcpy(b, d);
	_stcat(b, "/");
	_stcat(b, HIT_DOC);
	return (b);
}

/**
 * wrihis - A function that writes history
 * @x: input parameter
 * Return: 1
 */

int wrihis(data_t *x)
{
	ssize_t fd;
	char *fn = gethis(x);
	file_t *ia = NULL;

	if (!fn)
		return (-1);

	fd = open(fn, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(fn);
	if (fd == -1)
		return (-1);

	for (ia = x->htr; ia; ia = ia->next)
	{
		_putsf(ia->str, fd);
		_putf('\n', fd);
	}
	_putf(SCR_FLUSH, fd);
	close(fd);
	return (1);
}

/**
 * rehis - A function that read history
 * @x: input parameter
 * Return: 0
 */

int rehis(data_t *x)
{
	int i, j = 0, l = 0;
	ssize_t fd, r, fs = 0;
	struct s;
	char *b = NULL, *fn = gethis(x);

	if (!fn)
		return (0);
	fd = open(fn, O_RDONLY);
	free(fn);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fs = st.st_size;
	if (fs < 2)
		return (0);
	b = malloc(sizeof(char) * (fs + 1));
	if (!b)
		return (0);
	r = read(fd, b, fs);
	b[fs] = 0;
	if (r <= 0)
		return (free(b), 0);
	close(fd);
	for (i = 0; i < fs; i++)
		if (b[i] == '\n')
		{
			b[i] = 0;
			buhisl(x, b + j, l++);
			j = i + 1;
		}
	if (j != i)
		buhisl(x, b + j, l++);
	free(b);
	x->hiscou = l;
	while (x->hiscou-- >= HIT_MAX)
		delnode(&(x->htr), 0);
	renhis(x);
	return (x->hiscou);
}

/**
 * buhisl - A function that build history list
 * @x: input argument
 * @b: buffer
 * @l: history linecount
 * Return: 0
 */

int buhisl(data_t *x, char *b, int l)
{
	file_t *ia = NULL;

	if (x->htr)
		ia = x->htr;
	addnode(&ia, b, l);

	if (!x->htr)
		x->htr = ia;
	return (0);
}
