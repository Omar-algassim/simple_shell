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
	int acc;
	
	if (tok_line[0][0] != '/')
	{
		all_path = my_strdup(getenv("PATH"));
		tok_path = token_it(all_path, ":");
		
		if (tok_path == NULL)
		{
			free(all_path);
			return (NULL);
		}
		while (tok_path[i] != NULL)
		{
			size = strlen(tok_path[i]) + strlen(tok_line[0]) + 2;
			path_cmd = malloc(sizeof(char) * size);
			if (path_cmd == NULL)
			{
				perror("malloc");
				free(tok_path);
				return (NULL);
			}
			else
			{
			path_cmd = my_strdup(tok_path[i]);
			strcat(path_cmd, "/");
		 	strcat(path_cmd, tok_line[0]);
			tok_path[i] = my_strdup(path_cmd);
			free(path_cmd);
			}
			i++;
		}
	free(all_path);
	return (tok_path);
	}
return (tok_line);
}

