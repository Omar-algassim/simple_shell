#include "shell.h"

/**
 * token_it - function tokinaze the string
 * @str: the string will tokinaze
 * @del: the delimeter will token on it
 * Return: the tokinaze string in douple pinter
 */

char **token_it(char *str, char *del)
{
	char **token = NULL;
	char *tok = NULL;
	int j, i = 0;
	char *cpy = _strdup(str);

	if (str == NULL || del == NULL)
	{
		perror("token");
		return (NULL);
	}
	tok = strtok(cpy, del);
	while (tok != NULL)
	{
		token = realloc(token, sizeof(char *) * (i + 1));
		if (token == NULL)
		{
			perror("realloc");
			free(cpy);
			return (NULL);
		}
		token[i] = _strdup(tok);
		if (token[i] == NULL)
		{
			perror("strdup");
			free(cpy);
			free_tok(token);
			return (NULL);
		}
		tok = strtok(NULL, del);
		i++;
	}
	token = realloc(token, sizeof(char *) * (i + 1));
	if (token == NULL)
	{
		perror("realloc");
		free(cpy);
		return (NULL);
	}
	token[i] = NULL;
	free(tok);
	free(cpy);
	return (token);
}

