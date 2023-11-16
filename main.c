#include "shell.h"

/**
 * main - get line command from stdin and tokine it
 *@argc: the number of arg
 *@arg: the args pass to execute
 *@env: the system envirument
 * Return: always 0
 */

int main(int argc __attribute__ ((unused)), char **arg, char **env)
{
	char **cmd_path = NULL, *line = NULL;
	int getcheck, cmd_count = 0, status = 0;
	size_t len = 0;

	while (1)
	{
		cmd_count++;
		if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
		getcheck = getline(&line, &len, stdin);
		line = h_exit(line, getcheck, status);
		if (_strcmp(line, "env") == 0)
			_env(env);
		else if (line != NULL)
		{
			arg = token_it(line, " ");
			if (arg != NULL && arg[0] != NULL)
			{
				if (arg[0][0] != '/' && arg[0][0] != '.')
				{
					cmd_path = path(arg);
					if (cmd_path != NULL && cmd_path[0] != NULL)
					{
						status = execute(cmd_path, arg, env, cmd_count);
						free_tok(cmd_path);
					}
					else
					{
						status = execute(cmd_path, arg, env, cmd_count);
					}
				}
				else
					status = execute(arg, arg, env, cmd_count);
			}
			free_tok(arg);
		}
	}
	free(line);
	return (0);
}
