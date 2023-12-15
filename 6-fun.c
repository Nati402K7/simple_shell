#include "main.h"

/**
 * decnum - A function that prints decimal number
 * @in: input value
 * @f: filedescriptor
 * Return: number of decimal
 */

int decnum(int in, int f)
{
        int (*__putchar)(char) = _putchar;
        int i, c = 0;
        unsigned int j, k;

        if (f == STDERR_FILENO)
                __putchar = _iputchar;

        if (in < 0)
        {
                j = -in;
                __putchar('-');
                c++;
        }
	else
                j = in;
        k = j;
        for (i = 1000000000; i > 1; i /= 10)
        {
                if (j / i)
                {
                        __putchar('0' + k / i);
                        c++;
                }
                k %= i;
        }
        __putchar('0' + k);
        c++;

        return (c);
}

/**
 * _isalp - A function that check alphabetic order
 * @c: input character
 * Return: 1 if sorted, otherwith 0
 */
 
int _isalp(int c)
{
        if ((c >= '97' && c <= '122') || (c >= '65' && c <= '90'))
                return (1);
        else
                return (0);
}
