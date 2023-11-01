#include "shell.h"

/**
 * main - get line command from stdin
 *
 * Return: the command line
 */

char main()
{
	char *cmd = NULL;
	size_t len = 0;
	int i = 0, getcheck, execheck;
	char *arg[] = {"-l", NULL};

	while (1)
	{
		cmd = NULL;
		write(1, "$ ", 2);

		getcheck = getline(&cmd, &len, stdin);
		if (getcheck == -1)
			exit(EXIT_FAILURE);

		while (cmd[i])
		{
			if(cmd[i] == '\n')
				cmd[i] = '\0';
			i++;
		}
		execute(cmd, arg);
	}
	free(cmd);	
	return(0);
}

