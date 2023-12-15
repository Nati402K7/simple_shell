#include "main.h"


/**
 * renhis - A function that renumber history
 * @x: input argument
 * Return: number of history
 */

int renhis(data_t *x)
{
	file_t *ia = x->htr;
	int i = 0;

	while (ia)
	{
		ia->num = i++;
		ia = ia->next;
	}
	return (x->hiscou = i);
}
