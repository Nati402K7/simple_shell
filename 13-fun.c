#include "main.h"

/**
 * _env - A function that prints the environment
 * @x: input info
 * Return: 0
 */

int _env(data_t *x)
{
        prlisele(x->env);
        return (0);
}

/**
 * poenvl - A function that populates env list
 * @x: input info
 * Return: 0
 */

int poenvl(data_t *x)
{
        file_t *ia = NULL;
        size_t i;

        for (i = 0; envp[i]; i++)
                addnode(&ia, envp[i], 0);
        x->env = ia;

        return (0);
}
