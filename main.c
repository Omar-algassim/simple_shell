#include "shell.h"

/**
 * main - get line command from stdin and tokine it
 *@argc: the number of arg
 *@arg: the args pass to execute
 *@env: the system envirument
 * Return: always 0
 */

int main(int argc, char **arg, char **env)
{
	char **cmd_path = NULL, *line = NULL;
	size_t line_length, getcheck, len = 0;
	int i = 0;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		getcheck = getline(&line, &len, stdin);
		if (getcheck == -1 || _strcmp(line, "exit\n") == 0)
		{
			write(STDOUT_FILENO, "exit\n", 5);
			free(line);
			exit(EXIT_SUCCESS);
		}
		else if (_strcmp(line, "env\n") == 0)
			_env(env);
		else if (line != NULL)
		{
			line_length = _strlen(line);
			if (line_length > 0 && line[line_length - 1] == '\n')
				line[line_length - 1] = '\0';
				arg = token_it(line, " ");
				if (arg != NULL && arg[0] != NULL)
				{
					if (arg[0][0] != '/')
					{
						cmd_path = path(arg);
						if (cmd_path != NULL && cmd_path[0] != NULL)
						{
							execute(cmd_path, arg, env);
							//free_tok(cmd_path);
							//free(line);
						}
					}
					else
						execute(arg, arg, env);
				}
			free_tok(arg);
				
		}
	}
	free(line);
	return (0);
}
