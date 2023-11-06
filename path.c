#include "shell.h"

/**
 * path - get the execute pathe and append the command
 * @cmd: the command
 * Return: the full path of execut
 */

char **path(char **tok_line)
{
	char *all_path = NULL;
	char **tok_path = NULL;
	char *path_cmd = NULL;
	char *cmd = NULL;
	int i = 0;
	size_t size = 0;
	
	if (tok_line[0][0] != '/')
	{
		all_path = _strdup(getenv("PATH"));
		tok_path = token_it(all_path, ":");
		
		if (tok_path == NULL)
		{
			free(all_path);
			return (NULL);
		}
		while (tok_path[i] != NULL)
		{
			size = _strlen(tok_path[i]) + _strlen(tok_line[0]) + 2;
			path_cmd = malloc(size);
			if (path_cmd == NULL)
			{
				perror("malloc");
				free(tok_path);
				return (NULL);
			}
			else
			{
			_strcpy(path_cmd, tok_path[i]);
			_strcat(path_cmd, "/");
		 	_strcat(path_cmd, tok_line[0]);
			tok_path[i] = _strdup(path_cmd);
			free(path_cmd);
			}
			i++;
		}
	free(all_path);
	return (tok_path);
	}
}

