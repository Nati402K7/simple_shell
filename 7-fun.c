#include "main.h"

/**
 * _reall - A function that reallocates a memory
 * @p: pointer
 * @o: old size
 * @n: new size
 */

void *_reall(void *p, unsigned int o, unsigned int n)
{
        char *i;

        if (!p)
                return (malloc(n));

        if (!n)
                return (free(p), NULL);

        if (n == o)
                return (p);

        i = malloc(n);

        if (!i)
                return (NULL);
	
	o = o < n ? o : n;
        while (o--)
                p[o] = ((char *)p)[o];
        free(p);
        return (i);
}

/**
 * delm - A function that checks dilemeter character
 * @c: input character
 * @d: the string that we use
 * Return:1 if success, otherwith 0
 */

int delm(char c, char *d)
{
        while (*d)
                if (*d++ == c)
                        return (1);
        return (0);
}

/**
 * conum - A function that convert func to string
 * @n: input number
 * @b: base number
 * @ar: argument
 * Return: string
 */

char *conum(long int n, int b, int ar)
{
        static char *k;
        static char l[50];
        char s = 0;
        char *p;
        unsigned long i = n;

        if (!(ar & CHANGE_UNSIGNED) && n < 0)
        {
                i = -n;
                s = '-';
        }
        k = ar & CHANGE_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
        p = &l[49];
        *p = '\0';

	do {
                *--p = k[i % b];
                i /= b;
        } while (i != 0);

        if (s)
                *--p = s;
        return (p);
}
