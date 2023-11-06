#include "shell.h"

/**
 * free_tok - free to douple pointer
 * @tok: the douple pointer want to free
 * Return: nothing
 */
void free_tok(char **tok)
{
	int i;

	for (i = 0; tok[i] != NULL; i++)
	{
		free(tok[i]);
	}
	free(tok);
}

