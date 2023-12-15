#include "main.h"

/**
 * fstr - A function that free a string
 * @s: string
 */

void fstr(char **s)
{
        char **i = s;

        if (!s)
                return;
        while (*s)
                free(*s++);
        free(i);
}

/**
 * fadd - A function that frees the address
 * @p: input address of pointer
 * Return: 1 if success, otherwith 0
 */

int fadd(void **p)
{
        if (p && *p)
        {
                free(*p);
                *p = NULL;
                return (1);
        }
        return (0);
}
