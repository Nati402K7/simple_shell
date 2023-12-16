#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define SHELL_NORM 0
#define SHELL_OR 1
#define SHELL_AND 2
#define SHELL_CHAIN 3
#define SCAN_SCR_SIZE 1024
#define LIST_SCR_SIZE 1024
#define SCR_FLUSH -1
#define USE_GETLINE 0
#define USE_STRTOK 0
#define CHANGE_LOWERCASE 1
#define CHANGE_UNSIGNED 2
#define HIT_DOC ".sshis"
#define HIT_MAX 4096

extern char **envelop;

/**
 * struct filestr - singly linked list
 * @num: the number filed
 * @str: a string
 * @next: points to the next node
 */

typedef struct filestr
{
	int num;
	char *str;
	struct filestr *next;
} file_t;

/**
 * struct lastdata - A function that allowing uniform prototype
 * @a: arguments
 * @as: array of strings
 * @p: a string path
 * @ac: argument count
 * @ec: error count
 * @en: error code
 * @li: line of input
 * @pfn: program filename
 * @env: local copy of envelop
 * @envp: copy of envelop
 * @htr: history node
 * @ali: alias node
 * @envc: envelop was changed
 * @sts: return status
 * @sscr: address of pointer
 * @sscrt: command type
 * @sfd: to read line input
 * @hiscou: line number of history count
 */

typedef struct lastdata
{
	int ac, en, li, envc, sts, sscrt, sfd, hiscou;
	char *a, **as, *p, *pfn, **envp, **sscr;
	unsigned int ec;
	file_t *env, *htr, *ali;
} data_t;


#define DATA_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 * struct buitin - A function that contains a builtin string
 * @t: the builtin command
 * @f: the function
 */

typedef struct buitin
{
	char *type;
	int (*func)(data_t *);
} builtin_fun;

int _isalp(int);
int _snum(char *);
int fadd(void **);
int _cd(data_t *);
int _putchar(char);
int _stlen(char *);
int _senum(char *);
int _env(data_t *);
int iact(data_t *);
int _iputchar(char);
int _strlen(char *);
int _help(data_t *);
int rehis(data_t *);
int _sexit(data_t *);
int decnum(int, int);
int _alias(data_t *);
int _lihis(data_t *);
int _rmenv(data_t *);
int repvar(data_t *);
int _putf(char, int);
int poenvl(data_t *);
int wrihis(data_t *);
int renhis(data_t *);
int _setenv(data_t *);
int delm(char, char *);
int repalias(data_t *);
int f_builtin(data_t *);
int _putsf(char *, int);
int pralias(data_t *ia);
int _stcmp(char *, char *);
int _cmd(data_t *, char *);
int _loop(data_t *, char **);
int repstr(char **, char **);
int salias(data_t *, char *);
int rmalias(data_t *, char *);
int _rmenvinf(data_t *, char *);
int buhisl(data_t *, char *, int);
int _senv(data_t *, char *, char *);
int _cha(data_t *, char *, size_t *);
int delnode(file_t **, unsigned int);
int _gline(data_t *, char **, size_t *);

char *gethis(data_t *);
char **genvi(data_t *);
char *_stdup(const char *);
char *_stchr(char *, char);
char **stsplw(char *, char);
char **arrstrings(file_t *);
char **stspl(char *, char *);
char *_stcpy(char *, char *);
char *_stcat(char *, char *);
char *conum(long int, int, int);
char *dipchar(char *, int, int);
char *_stncat(char *, char *, int);
char *_stncpy(char *, char *, int);
char *_genv(data_t *, const char *);
char *fpath(data_t *, char *, char *);
char *_memos(char *, char, unsigned int);
char *hashtack(const char *, const char *);

void handler(int);
void rcomm(char *);
void _puts(char *);
void fstr(char **);
void _iputs(char *);
void fcmd(data_t *);
void focmd(data_t *);
void clearer(data_t *);
void finf(data_t *, int);
void free_list(data_t **);
void perr(data_t *, char *);
void freenode(file_t **);
void sinfo(data_t *, char **);
void *_reall(void *, unsigned int, unsigned int);
void che_cha(data_t *, char *, size_t *, size_t, size_t);

ssize_t ginp(data_t *);
size_t lislen(const file_t *);
size_t prlist(const file_t *);
size_t prlisele(const file_t *);
ssize_t gnodein(file_t *, file_t *);
ssize_t hoinp(data_t *, char **, size_t *);
ssize_t rbuf(data_t *, char *, size_t *);

file_t *nodest(file_t *, char *, char);
file_t *adnode(file_t **, const char *, int);
file_t *addnode(file_t **, const char *, int);

#endif
