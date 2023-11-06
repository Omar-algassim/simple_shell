#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
/*prototype*/

void _env(char **env);
void free_tok(char **tok);
int execute(char **path_cmd, char **arg, char **env);
char **path(char **tok_line);
char **token_it(char *str, char *del);
char *get_line();
char *_getenv(char *env_var);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strdup(const char *str);
char *_strchr(const char *s, int c);
unsigned int _strspn(char *s, char *accept);
size_t _strcspn(const char *s1, const char *s2);
void h_exit(char *command);
char *_strtok(char *str, const char *delim);

#endif
