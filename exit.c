#include "shell.h"

/**
 * h_exit - function that delet new line and
 * terminate the program when user types "exit".
 * and print env when user type "env"
 *
 * @command: the string to be read.
 * @getcheck: the getline return
 * Return: command without the '\n'
 *
 */
char *h_exit(char *command, int getcheck)
{
	int len;

	if (command != NULL)
	{
		if (getcheck == -1)
		{
			free(command);
			exit(EXIT_SUCCESS);
		}
		else
		{
			len = _strlen(command);
			command[len - 1] = '\0';
		}
	}
return (command);
}
