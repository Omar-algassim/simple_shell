#include "shell.h"

/**
 * execute - exxecute the got command
 * @path_cmd: the path of file should execute
 * @arg: the whole line of command
 * @env: the eniroment varuable
 * @cmd_count: the number of command
 * Return: 0 if success
 */

int execute(char **path_cmd, char **arg, char **env, int cmd_count)
{
	pid_t pid;
	int acc, exe, status, exit_status;
	char *cmd = NULL;

	cmd = _access(path_cmd);
	if (cmd != NULL)
		acc = access(cmd, X_OK);

	if (acc == -1 || cmd == NULL)
	{
		exit_status = 127;
		free(cmd);
		dprintf(STDERR_FILENO, "./hsh: %d: %s: not found\n", cmd_count, arg[0]);
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
			exit_status = WEXITSTATUS(status);
	}
return (exit_status);
}

