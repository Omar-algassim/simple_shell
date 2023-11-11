#include "shell.h"

/**
 * execute - exxecute the got command
 * @path_cmd: the path of file should execute
 * @arg: the whole line of command
 * @env: the eniroment varuable
 * Return: 0 if success
 */

int execute(char **path_cmd, char **arg, char **env)
{
	pid_t pid;
	int acc, exe, status, i = 0;
	char *cmd = NULL;


	while (path_cmd[i] != NULL)
	{
		acc = access(path_cmd[i], F_OK);
		if (acc == 0)
		{
			cmd = path_cmd[i];
		}
		i++;
	}
	if (cmd != NULL)
		acc = access(cmd, F_OK);
	if (acc == -1)
	{
		free(cmd);
		perror(arg[0]);
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
	return (0);
}
