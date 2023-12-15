#include "main.h"

/**
 * _rmenvinf - A function that remove environment info
 * @x: input info
 * @v: env variable
 * Return: environment changed or 0
 */

int _rmenvinf(data_t *x, char *v)
{
        file_t *ia = x->env;
        size_t i = 0;
        char *p;

        if (!ia || !v)
                return (0);

        while (ia)
        {
                p = hashtack(ia->str, v);
                if (p && *p == '=')
                {
                        x->envc = delnode(&(x->env), i);
                        i = 0;
                        ia = x->env;
                        continue;
                }
                ia = ia->next;
                i++;
        }
        return (x->envc);
}

/**
 * _senv - A function that set environment
 * @x: input info
 * @v: variable
 * @s: string
 * Return: 0 if success, otherwith 1
 */

int _senv(data_t *x, char *v, char *s)
{
        char *b = NULL;
        file_t *ia;
        char *p;

        if (!v || !s)
                return (0);

        b = malloc(_stlen(v) + _stlen(s) + 2);
        if (!b)
                return (1);
        _stcpy(b, v);
        _stcat(b, "=");
        _stcat(b, s);
        ia = x->env;

	while (ia)
        {
                p = hashtack(ia->str, v);
                if (p && *p == '=')
                {
                        free(ia->str);
                        ia->str = b;
                        x->envc = 1;
                        return (0);
                }
                ia = ia->next;
        }
        add_node_end(&(x->env), b, 0);
        free(b);
        x->envc = 1;
        return (0);
}
