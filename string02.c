#include "shell.h"

/**
 * _strdup - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 2));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}

/**
 * _strchr - Entry point
 * @s: input
 * @c: input
 * Return: Always 0 (Success)
 */

char *_strchr(const char *s, int c)
{
	while (*s != (char)c)
		if (!*s++)
			return (0);
	return ((char *)s);
}

/**
 * _strspn - Entry point
 * @s: input
 * @accept: input
 * Return: Always 0 (Success)
 */

unsigned int _strspn(char *s, char *accept)
{
	unsigned int n = 0;
	int r;

	while (*s)
	{
		for (r = 0; accept[r]; r++)
		{
			if (*s == accept[r])
			{
				n++;
				break;
			}
			else if (accept[r + 1] == '\0')
				return (n);
		}
		s++;
	}
	return (n);
}

/**
 * _strcspn - computes the length of the maximum initial segment of the string
 * pointed to by s1which consists entirely of characters not from the
 * string pointed to by s2.
 * @s1: string to check
 * @s2: string useful to compare
 * Return: the length of the segment.
 **/
size_t _strcspn(const char *s1, const char *s2)
{
	size_t ret = 0;

	while (*s1)
	{
		if (_strchr(s2, *s1))
			return (ret);
		s1++, ret++;
	}
	return (ret);
}
