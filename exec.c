#include "shell.h"

/**
 * execute - exxecute the got command
 * @cmd: the command should to execute
 * Return: 1 if success -1 if fail
 */

int execute(char **path_cmd, char **arg, char **env)
{
	pid_t pid;
	int acc, exe;
	int status;
	char *cmd = NULL;
	int i = 0;

	while (path_cmd[i] != NULL)
	{
		acc = access(path_cmd[i], F_OK);
		if (acc == 0)
		{
		//	cmd = malloc(_strlen(path_cmd[i]) + 1);
			cmd = strdup(path_cmd[i]);
		}

			i++;
	}
	free_tok(path_cmd);
	if (cmd != NULL)
		acc = access(cmd, X_OK);
	if (acc == -1)
		{
			perror(cmd);
		}
	if (acc == 0)
		{
			pid = fork();
			if (pid == -1)
				perror("fork");

			if (pid == 0)
			{
				exe = execve(cmd, arg, env);
				if (exe == -1)
				{
					perror("bash");
					free(cmd);
					exit(EXIT_FAILURE);
				}
			}
		
		waitpid(pid, &status, 0);
		}
	free(cmd);
	return (0);
}
