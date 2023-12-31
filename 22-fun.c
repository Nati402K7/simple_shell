#include "main.h"

/**
 * _stdup - A function that duplicats a string
 * @s: input string
 * Return: address of the duplicated string
 */

char *_stdup(const char *s)
{
	int l = 0;
	char *i;

	if (s == NULL)
		return (NULL);

	while (*s++)
		l++;
	i = malloc(sizeof(char) * (l + 1));

	if (!i)
		return (NULL);

	for (l++; l--;)
		i[l] = *--s;
	return (i);
}

/**
 * _stncpy - A function that copy a given string
 * @f: given destination of the string
 * @s: input string
 * @n: the input string amout of character index
 * Return: string copied
 */

char *_stncpy(char *f, char *s, int n)
{
	int i, j;
	char *k = f;

	i = 0;
	while (s[i] != '\0' && i < n - 1)
	{
		f[i] = s[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			f[j] = '\0';
			j++;
		}
	}
	return (k);
}

/**
 * _stncat - A function that concatnated to strings
 * @f: address of the the first input string
 * @s: the string to concatnate
 * @n: the amount of the concatnated string
 * Return: concatnated string
 */

char *_stncat(char *f, char *s, int n)
{
	int i, j;
	char *k = f;

	i = 0;
	j = 0;
	while (f[i] != '\0')
		i++;

	while (s[j] != '\0' && j < n)
	{
		f[i] = s[j];
		i++;
		j++;
	}
	if (j < n)
		f[i] = '\0';
	return (k);
}


/**
 * _stchr - A function that locates a character string
 * @s: input string
 * @c: input character
 * Return: the character that located
 */

char *_stchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

/**
 * stspl - A function that splits a string into words
 * @s: input string
 * @n: the number of spliter string
 * Return: number of pointers of string
 */

char **stspl(char *s, char *n)
{
	int i, j, k, m, w = 0;
	char **p;

	if (s == NULL || s[0] == 0)
		return (NULL);
	if (!n)
		n = " ";
	for (i = 0; s[i] != '\0'; i++)
		if (!delm(s[i], n) && (delm(s[i + 1], n) || !s[i + i]))
			w++;
	if (w == 0)
		return (NULL);
	p = malloc((1 + w) * sizeof(char *));
	if (!p)
		return (NULL);
	for (i = 0, j = 0; j < w; j++)
	{
		while (delm(s[i], n))
			i++;
		k = 0;
		while (!delm(s[i + k], n) && s[i + k])
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
