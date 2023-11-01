#include "shell.h"

/**
 * execute - exxecute the got command
 * @cmd: the command should to execute
 * Return: 1 if success -1 if fail
 */

int execute(char *cmd, char **arg)
{
	pid_t pid;
	int acc, exe;
	int status;
	acc = access(cmd, F_OK);

	if (acc == -1)
		{
			exit(EXIT_FAILURE);
		}
	if (acc == 0)
		{
			pid = fork();
			if (pid == -1)
				perror("fork");

			if (pid == 0)
			{
				exe = execve(cmd, arg, NULL);
				if (exe == -1)
				{
					perror("bash");
				}
			}
			else
				waitpid(pid, &status, 0);
		}
return (0);
}
