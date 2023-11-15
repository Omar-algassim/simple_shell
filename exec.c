#include "shell.h"

/**
 * execute - exxecute the got command
 * @path_cmd: the path of file should execute
 * @arg: the whole line of command
 * @env: the eniroment varuable
 * Return: 0 if success
 */

int execute(char **path_cmd, char **arg, char **env, int cmd_count)
{
	pid_t pid;
	int acc, exe, status, i = 0;
	char *cmd = NULL;
	int exit_status;

	while (path_cmd[i] != NULL)
	{
		acc = access(path_cmd[i], X_OK);
		if (acc == 0)
		{
			cmd = path_cmd[i];
		}
		i++;
	}
	if (cmd != NULL)
		acc = access(cmd, X_OK);
	if (acc == -1)
	{
		free(cmd);
		write(STDERR_FILENO, &cmd_count, sizeof(int));
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
	       	if (WIFEXITED(status)) 
		 {
			 exit_status = WEXITSTATUS(status);
		 }
	}
return (exit_status);
}

