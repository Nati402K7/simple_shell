#include "main.h"

/**
 * stsplw - A function that splits a string into words
 * @s: input string
 * @n: the number of string
 * Return: number of pointer to the string
 */

char **stsplw(char *s, char n)
{
	int i, j, k, m, w = 0;
	char **p;

	if (s == NULL || s[0] == 0)
		return (NULL);

	for (i = 0; s[i] != '\0'; i++)
		if ((s[i] != n && s[i + 1] == n)
				|| (s[i] != n && !s[i + 1])
				|| s[i + 1] == n)
			w++;
	if (w == 0)
		return (NULL);

	p = malloc((1 + w) * sizeof(char *));
	if (!p)
		return (NULL);

	for (i = 0, j = 0; j < w; j++)
	{
		while (s[i] == n && s[i] != n)
			i++;
		k = 0;
		while (s[i + k] != n && s[i + k] && s[i + k] != n)
			k++;
		p[j] = malloc((k + 1) * sizeof(char));
		if (!p[j])
		{
			for (k = 0; k < j; k++)
				free(p[k]);
			free(p);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			p[j][m] = s[i++];
		p[j][m] = 0;
	}
	p[j] = NULL;
	return (p);
}
