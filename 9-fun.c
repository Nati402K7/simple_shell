#include "main.h"

/**
 * _snum - A function that convert string to number
 * @s: input string
 * Return: converted number
 */

int _snum(char *s)
{
        int i, j = 1, k = 0, l;
        unsigned int r = 0;

        for (i = 0; s[i] != '\0' && k != 2; i++)
        {
                if (s[i] == '-')
                        j *= -1;

                if (s[i] >= '0' && s[i] <= '9')
                {
                        k = 1;
                        r *= 10;
                        r += (s[i] - '0');
                }
                else if (k == 1)
                        k = 2;
        }

        if (j == -1)
                l = -r;
        else
                l = r;

        return (l);
}

/**
 * _senum - A function that convert string to number
 * @s: input string
 * Return: converted string
 */

int _senum(char *s)
{
        int i = 0;
        unsigned long int j = 0;

        if (*s == '+')
                s++;

        for (i = 0; s[i] != '\0'; i++)
        {
                if (s[i] >= '0' && s[i] <= '9')
                {
                        j *= 10;
                        j += (s[i] - '0');
                        if (j > INT_MAX)
                                return (-1);
                }
                else
                        return (-1);
        }
        return (j);
}
