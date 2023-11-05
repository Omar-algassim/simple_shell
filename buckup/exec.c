#include "shell.h"

/**
 * execute - exxecute the got command
 * @cmd: the command should to execute
 * Return: 1 if success -1 if fail
 */

int execute(char *cmd)
{
	pid_t pid;
	int acc, exe;
	int status;
	char *const arg[] = {cmd, NULL};
	
	acc = access(cmd, X_OK);
	if (acc == -1)
		{
			perror("bash");
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
				exit(EXIT_FAILURE);
				}
			}
		
		waitpid(pid, &status, 0);	
		}
	return (0);
}
