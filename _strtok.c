#include "shell.h"

/**
 * test_del - Test If Char Match Any Char *.
 * @c: character to test
 * @str: string to test
 * Return: 1 succes, 0 Failed
*/

unsigned int test_del(char s, const char *str)
{
	unsigned int u;

	for (u = 0; str[u] != '\0'; u++)
	{
		if (s == str[u])
			return (1);
	}
	return (0);
}

/**
 * _strtok - breaks string str into a series of tokens using the delimiter delim.
 * @str: string to tokenize
 * @delim: string delimit str
 * Return: pointer to the next token, null-pointer otherwise.
*/
char *_strtok(char *str, const char *delim)
{
	static char *x, *p;
	unsigned int y;

	if (str != NULL)
		p = str;
	x = p;
	if (x == NULL)
		return (NULL);
	for (y = 0; x[y] != '\0'; y++)
	{
		if (test_del(x[y], delim) == 0)
			break;
	}
	if (p[y] == '\0' || p[y] == '#')
	{
		p = NULL;
		return (NULL);
	}
	x = p + y;
	p = x;
	for (y = 0; p[y] != '\0'; y++)
	{
		if  (test_del(p[y], delim) == 1)
			break;
	}
	if (p[y] == '\0')
		p = NULL;
	else
	{
		p[y] = '\0';
		p = p + y + 1;
		if (*p == '\0')
			p = NULL;
	}
	return (x);
}

