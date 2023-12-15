#include "main.h"


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
