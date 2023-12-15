#include "main.h"

/**
 * _cha - A function that checkes chain
 * @x: input parameter
 * @b: buffer
 * @p: place of the buffer
 * Return: 1
 */

int _cha(data_t *x, char *b, size_t *p)
{
        size_t j = *p;

        if (b[j] == '|' && b[j + 1] == '|')
        {
                b[j] = 0;
                j++;
                x->sscrt = SHELL_OR;
        }
        else if (b[j] == '&' && b[j + 1] == '&')
        {
                b[j] = 0;
                j++;
                x->sscrt = SHELL_AND;
        }
        else if (b[j] == ';')
        {
                b[j] = 0;
                x->sscrt = SHELL_CHAIN;
        }
	else
                return (0);
        *p = j;
        return (1);
}

/**
 * che_cha - A function that checks chain
 * @x: input parameter
 * @b: buffer
 * @a: address of buffer
 * @f: first postion of buffer
 * @l: length of buffer
 */

void che_cha(data_t *x, char *b, size_t *a, size_t f, size_t l)
{
        size_t j = *a;

	 if (x->sscrt == SHELL_AND)
        {
                if (x->sts)
                {
                        b[i] = 0;
                        j = l;
                }
        }
        if (x->sscrt == SHELL_OR)
        {
                if (!x->sts)
                {
                        b[i] = 0;
                        j = l;
                }
        }
        *a = j;
}
