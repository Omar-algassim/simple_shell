#include "shell.h"

/**
 * h_exit - function that terminate the program when user types "exit".
 *
 * @command: the string to be read.
 *
 * Return: nothing.
 *
 */
void h_exit(char *command)
{
	if (_strcmp("exit", command) == 0)
	{
		free(command);
		exit(EXIT_SUCCESS);
	}
}
