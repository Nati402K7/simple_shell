#include "main.h"

/**
 * _sexit - A function that makes you exit shell
 * @x: input info
 * Return: exit
 */

int _sexit(data_t *x)
{
	int i;

	if (x->as[1])
	{
		i = _senum(x->as[1]);
		if (i == -1)
		{
			x->sts = 2;
			perr(x, "un known number: ");
			_iputs(x->as[1]);
			_iputchar('\n');
			return (1);
		}
		x->en = _senum(x->as[1]);
		return (-2);
	}
	x->en = -1;
	return (-2);
}

/**
 * _cd - A function that changes current directory
 * @x: input info
 * Return: 0
 */

int _cd(data_t *x)
{
	char *s, *d, b[1024];
	int i;

	s = getcwd(b, 1024);
	if (!s)
		_puts("TODO: >>getcwd fail here<<\n");
	if (!x->as[1])
	{
		d = _genv(x, "HOME=");
		if (!d)
			i = chdir((d = _genv(x, "PWD=")) ? d : "/");
		else
			i = chdir(d);
	}
	else if (_stcmp(x->as[1], "-") == 0)
	{
		if (!_genv(x, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_genv(x, "OLDPWD=")), _putchar('\n');
		i = chdir((d = _genv(x, "OLDPWD=")) ? d : "/");
	}
	else
		i = chdir(x->as[1]);
	if (i == -1)
	{
		perr(x, "coudn't cd to the ");
		_iputs(x->as[1]), _iputchar('\n');
	}
	else
	{
		_senv(x, "OLDPWD", _genv(x, "PWD="));
		_senv(x, "PWD", getcwd(b, 1024));
	}
	return (0);
}

/**
 * _help - A function that help the user
 * @x: input info
 * Return: 0
 */

int _help(data_t *x)
{
	char **i;

	i = x->as;
	_puts("help is ready to help, sorry function not yet implemented \n");
	if (0)
		_puts(*i);
	return (0);
}

/**
 * rmalias - A function that remove alias
 * @x: input parameter
 * @s: input string
 * Return: remove
 */

int rmalias(data_t *x, char *s)
{
	char *p, c;
	int i;

	p = _strchar(s, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	i = delnode(&(x->ali), gnodein(x->ali, nodest(x->ali, s, -1)));
	*p = c;

	return (i);
}

/**
 * salias - A function that set alias
 * @x: input parameter
 * @s: input string
 * Return: set alias or 1
 */

int salias(data_t *x, char *s)
{
	char *p;

	p = _stchr(s, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (rmalias(x, s));

	rmalias(x, s);
	return (addnode(&(x->ali), s, 0) == NULL);
}
