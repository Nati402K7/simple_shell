#include "main.h"

/**
 * adnode - A function that adds node
 * @h: head node address
 * @s: node string
 * @n: index node
 * Return: new head list
 */

file_t *adnode(file_t **h, const char *s, int n)
{
	file_t *new_head;

	if (!h)
		return (NULL);
	new_head = malloc(sizeof(file_t));

	if (!new_head)
		return (NULL);
	_memos((void *)new_head, 0, sizeof(file_t));
	new_head->n = n;
	if (s)
	{
		new_head->s = _stdup(s);
		if (!new_head->s)
		{
			free(new_head);
			return (NULL);
		}
	}
	new_head->next = *h;
	*h = new_head;
	return (new_head);
}

/**
 * addnode - A function that add node
 * @h: head node address
 * @s: node string
 * @n: index of node
 * Return: size of new node
 */

file_t *addnode(file_t **h, const char *s, int n)
{
	file_t *new_node, *ia;

	if (!h)
		return (NULL);

	ia = *h;
	new_node = malloc(sizeof(file_t));

	if (!new_node)
		return (NULL);
	_memos((void *)new_node, 0, sizeof(file_t));
	new_node->n = n;
	if (s)
	{
		new_node->s = _stdup(s);
		if (!new_node->s)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (ia)
	{
		while (ia->next)
			ia = ia->next;
		ia->next = new_node;
	}
	else
		*h = new_node;
	return (new_node);
}

/**
 * delnode - A function that deletes node
 * @h: first address of node
 * @in: index of node
 * Return: 1 if deleted, otherwith -1
 */

int delnode(file_t **h, unsigned int in)
{
	file_t *ia, *prev_node;
	unsigned int i = 0;

	if (!h || !*h)
		return (0);

	if (!in)
	{
		ia = *h;
		*h = (*h)->next;
		free(ia->str);
		free(ia);
		return (1);
	}
	ia = *h;
	while (ia)
	{
		if (i == in)
		{
			prev_node->next = ia->next;
			free(ia->str);
			free(ia);
			return (1);
		}
		i++;
		prev_node = ia;
		ia = ia->next;
	}
	return (0);
}

/**
 * nodest - A function that prints node string
 * @n: head pointer
 * @p: stating string
 * @c: the character value
 * Return: value of the node
 */

file_t *nodest(file_t *n, char *p, char c)
{
	char *i = NULL;

	while (n)
	{
		i = hashtack(n->str, prefix);
		if (i && ((c == -1) || (*i == c)))
			return (n);

		n = n->next;
	}
	return (NULL);
}
