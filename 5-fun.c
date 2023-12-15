#include "main.h"

/**
 * rcomm - A function that removes comments
 * @sa: string address
 */

void rcomm(char *sa)
{
	int i;

	for (i = 0; sa[i] != '\0'; i++)
		if (sa[i] == '#' && (!i || sa[i - 1] == ' '))
		{
			sa[i] = '\0';
			break;
		}
}
