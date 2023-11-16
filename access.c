#include "shell.h"

/**
 * _access - test the the file permission
 * @path_cmd: the path of file
 * Return: the executable file path
 */

char *_access(char **path_cmd)
{
	char *cmd = NULL;
	int i = 0;
	int acc;

	if (path_cmd == NULL)
		return (NULL);

	while (path_cmd[i] != NULL)
	{
		acc = access(path_cmd[i], F_OK);
		if (acc == 0)
		{
			cmd = path_cmd[i];
			break;
		}
		i++;
	}
return (cmd);
}

