#include "main.h"

/**
 * prlisele - A function that prints list string elements
 * @h: first input node
 * Return: list str size
 */

size_t prlisele(const file_t *h)
{
        size_t i = 0;

        while (h)
        {
                _puts(h->str ? h->str : "(nil)");
                _puts("\n");
                h = h->next;
                i++;
        }
        return (i);
}

/**
 * freenode - A function that free the node
 * @h: head node address
 */

void freenode(file_t **h)
{
        file_t *ia, *next_node, *head;

        if (!h || !*hr)
                return;
        head = *h;
        ia = head;

        while (ia)
        {
                next_node = ia->next;
                free(ia->str);
                free(ia);
                ia = next_node;
        }
        *h = NULL;
}

/**
 * lislen - A function that prints length of list
 * @h: first input node
 * Return: length of list
 */

size_t lislen(const file_t *h)
{
        size_t i = 0;

        while (h)
        {
                h = h->next;
                i++;
        }
        return (i);
}

/**
 * arrstrings - A function that prints array of string
 * @h: first input node
 * Return: list of string
 */

char **arrstrings(file_t *h)
{
        file_t *ia = h;
        size_t i = list_len(h), j;
        char **strs;
        char *str;

	 if (!h || !i)
                return (NULL);
        strs = malloc(sizeof(char *) * (i + 1));
        if (!strs)
                return (NULL);
        for (i = 0; ia; ia = ia->next, i++)
        {
                str = malloc(_stlen(ia->str) + 1);
                if (!str)
                {
                        for (j = 0; j < i; j++)
                                free(strs[j]);
                        free(strs);
                        return (NULL);
                }

                str = _stcpy(str, ia->str);
                strs[i] = str;
        }
        strs[i] = NULL;
        return (strs);
}

/**
 * prlist - A function that print list elements
 * @h: first input node
 * Return: list elements
 */

size_t prlist(const file_t *h)
{
        size_t i = 0;

        while (h)
        {
                _puts(convert_number(h->num, 10, 0));
                _putchar(':');
                _putchar(' ');
                _puts(h->str ? h->str : "(nil)");
                _puts("\n");
                h = h->next;
                i++;
        }
        return (i);
}

/**
 * gnodein - A function that get node index
 * @h: head pointers
 * @n: node pointers
 * Return: node index
 */

ssize_t gnodein(file_t *h, file_t *n)
{
        size_t i = 0;

        while (h)
        {
                if (h == n)
                        return (i);
                h = h->next;
                i++;
        }
        return (-1);
}