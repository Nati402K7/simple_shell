#include "main.h"

/**
 * _stlen - A function that returns the length of a string
 * @s: the input string
 * Return: length odf string
 */

int _stlen(char *s)
{
	int i = 0;

	if (!s)
		return (1);
	while (*s++)
		i++;
	return (i);
}

/**
 * _stcmp - A function that comparison of two strings.
 * @f: first input
 * @l: second input
 * Return: copared string
 */

int _stcmp(char *f, char *l)
{
	while (*f && *l)
	{
		if (*f != *l)
			return (*f - *l);
		f++;
		l++;
	}
	if (*f == *l)
		return (0);
	else
		return (*f < *l ? -1 : 1);
}

/**
 * hashtack - A function that finds that starts with #.
 * @s: search for string
 * @n: needed string
 * Return: valus of string
 */

char *hashtack(const char *s, const char *n)
{
	while (*n)
		if (*n++ != *s++)
			return (NULL);
	return ((char *)s);
}

/**
 * _stcat - A function that concatnet two string
 * @f: first string destination
 * @s: second string destination
 * Return: concatnet sting destination
 */

char *_stcat(char *f, char *s)
{
	char *i = f;

	while (*f)
		f++;
	while (*s)
		*f++ = *s++;
	*f = *s;
	return (i);
}


/**
 * _stcpy - A function that copies a string
 * @f: address of destination
 * @s: input string
 * Return: address of destination
 */

char *_stcpy(char *f, char *s)
{
	int i = 0;

	if (f == s || s == 0)
		return (f);

	while (s[i])
	{
		f[i] = s[i];
		i++;
	}
	f[i] = 0;
	return (f);
}
