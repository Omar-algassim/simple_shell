#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
/*prototype*/

char *get_line();
int execute(char *cmd);
char *_getenv(char *env_var);
void _env(void);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strdup(const char *str);
char *_strchr(char *s, char c);
unsigned int _strspn(char *s, char *accept);
size_t _strcspn(const char *s1, const char *s2);
void h_exit(char *command);
char *_strtok(char *str, const char *delim);

#endif
