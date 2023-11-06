#include "shell.h"

/**
 * _env - prints environment
 * @env: enviroment
 * Return: nothing
 */
void _env(char **env)
{
	int i = 0;

	while (env[i])
	{
		write(STDOUT_FILENO, env[i], _strlen(env[i]) + 1);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
