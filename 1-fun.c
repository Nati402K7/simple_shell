#include "main.h"

/**
 * f_builtin - A function that finds builtin command
 * @x: input parameter
 * Return: command
 */

int f_builtin(data_t *x)
{
	int i, j = -1;
	builtin_fun builtinfu[] = {
                {NULL, NULL},
                {"cd", _cd},
                {"env", _env},
                {"help", _help},
                {"exit", _sexit},
                {"alias", _alias},
                {"setenv", _setenv},
                {"history", _lihis},
                {"unsetenv", _rmenv}
        };
       	for (i = 0; builtinfu[i].type; i++)
		if (_stcmp(x->as[0], builtinfu[i].type) == 0)
		{
                        x->ec++;
                        j = builtinfu[i].func(x);
                        break;
                }
	return (j);
}

/**
 * _loop - A function that loops the shell
 * @x: input parameter
 * @ar: an argument
 * Return: if error have otherwith success
 */

int _loop(data_t *x, char **ar)
{
	ssize_t i = 0;
        int j = 0;

        while (i != -1 && j != -2)
        {
                clearer(x);
                if (iact(x))
                        _puts("$ ");
                _eputchar(SCREEN_FLUSH);
                i = ginp(x);
                if (i != -1)
                {
                        sinf(x, ar);
                        j = fbuiltin(x);
                        if (j == -1)
                                fcmd(x);
                }
		else if (iact(x))
			_putchar('\n');
                finf(x, 0);
        }
        wrihis(x);
        finf(x, 1);
        if (!iact(x) && x->sts)
                exit(x->sts);
        if (j == -2)
        {
                if (x->en == -1)
                        exit(x->sts);
                exit(x->en);
        }
        return (j);
}

/**
 * dipchar - A function that dipulicates character
 * @p: input path
 * @f: stating index
 * @l: stopping index
 * Return: point to dipulicated value
 */

char *dipchar(char *p, int f, int l)
{
        static char n[1024];
        int i = 0, k = 0;

        for (k = 0, i = f; i < l; i++)
                if (p[i] != ':')
                        n[k++] = p[i];
        n[k] = 0;
        return (n);
}

/**
 * fpath - a function that find path of command
 * @x: input parameter
 * @p: input path
 * @com: the command
 * Return: path of the command
 */

char *fpath(data_t *x, char *p, char *com)
{
        int i = 0, j = 0;
        char *n;

        if (!p)
                return (NULL);

        if ((_stlen(com) > 2) && hashtack(com, "./"))
        {
                if (_cmd(x, com))
                        return (com);
        }
	while (1)
        {
                if (!p[i] || p[i] == ':')
                {
                        n = dipchar(p, curr_pos, i);
                        if (!*n)
                                _stcat(n, com);
                        else
                        {
                                _stcat(n, "/");
                                _stcat(n, com);
                        }
                        if (_cmd(data, n))
                                return (n);
                        if (!p[i])
                                break;
                        curr_pos = i;
                }
                i++;
        }
        return (NULL);
}
