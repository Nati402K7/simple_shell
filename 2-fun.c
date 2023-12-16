#include "main.h"

/**
 * _cmd - A function that checkes if it is command
 * @x: input parenteses
 * @pa: path of the command
 * Return: 1 or 0
 */

int _cmd(data_t *x, char *pa)
{
	struct stat st;

	(void)x;
	if (!pa || stat(pa, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * fcmd - A function that find command
 * @x: input parameter
 */

void fcmd(data_t *x)
{
	char *pa = NULL;
	int i, k;

	x->pa = x->as[0];
	if (x->li == 1)
	{
		x->ec++;
		x->li = 0;
	}
	for (i = 0, k = 0; x->a[i]; i++)
		if (!delm(x->a[i], "\t\n"))
			k++;
	if (!k)
		return;
	pa = fpath(x, _genv(x, "PATH="), x->as[0]);
	if (pa)
	{
		x->pa = pa;
		focmd(x);
	}
	else
	{
		if ((iact(x) || _genv(x, "PATH=") ||
					x->as[0][0] == '/') &&
				_cmd(x, x->as[0]))
			focmd(x);
		else if (*(x->a) != '\n')
		{
			x->sts = 127;
			perr(x, "doesn't found\n");
		}
	}
}

/**
 * focmd - A function that fork a command
 * @x: input parameter
 */

void focmd(data_t *x)
{
	pid_t child_pid;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(x->p, x->as, genvi(x)) == -1)
		{
			finf(x, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(x->sts));
		if (WIFEXITED(x->sts))
		{
			x->sts = WEXITSTATUS(x->sts);
			if (x->sts == 126)
				perr(x, "This is permission\n");
		}
	}
}
