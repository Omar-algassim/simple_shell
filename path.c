#include "shell.h"

/**
 * path - get the execute pathe and append the command
 * @tok_line: the tokinaze command line
 * Return: the full path of execut
 */

char **path(char **tok_line)
{
	char *all_path = NULL;
	char **tok_path = NULL;
	int i = 0;
	size_t size = 0;

	if (tok_line[0][0] != '/')
	{
		all_path = _strdup(getenv("PATH"));
		tok_path = token_it(all_path, ":");
		free(all_path);
		if (tok_path == NULL)
			return (NULL);

		while (tok_path[i] != NULL)
		{
			size = _strlen(tok_path[i]) + _strlen(tok_line[0]) + 2;
			tok_path[i] = realloc(tok_path[i], size);
			if (tok_path[i] == NULL)
			{
				perror("malloc");
				free(tok_path);
				return (NULL);
			}
			else
			{
			_strcat(tok_path[i], "/");
			_strcat(tok_path[i], tok_line[0]);
			}
			i++;
		}
	}
	return (tok_path);

}
