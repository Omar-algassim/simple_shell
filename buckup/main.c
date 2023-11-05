#include "shell.h"

/**
 * main - get line command from stdin and tokine it
 *
 * Return: the command line
 */

int main()
{
	char *line = NULL;
	size_t len = 1024;
	int j, i = 0, getcheck, execheck;
	char **arg = NULL;
	char **cmd_path = NULL;
	while (1)
	{
		j = 0;
		write(1, "$ ", 2);

		getcheck = getline(&line, &len, stdin);
		if (getcheck == -1)
		{
			free(line);
			exit(EXIT_FAILURE);
		}
		else
		while (line[i] != '\0')
		{
			if(line[i] == '\n')
				line[i] = '\0';
			i++;
		}
		if (line != NULL && line != "\n")
		{
			arg = token_it(line, " ");
			cmd_path = path(arg);
		if (arg != NULL && cmd_path != NULL)
		{
		while (cmd_path[j] != NULL)
		{
			printf("%s\n", cmd_path[j]);
			free(cmd_path[j]);
			j++;
		}
		while (arg[j] != NULL)
		{
			//free(arg[j]);
			j++;
		}
		
		free(arg);
		//free(cmd_path);
		}
		}
	}
	return(0);
}

