#ifndef SHELL_H
#define SHELL_H
#define MAX_ARGS 64
#define DELIM " \t"
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

extern char **environ;

/**
 * env_builtin - prints the current environment variables
 *
 * Return: Always 0 (success)
 */

int exec(char *av[]);
char *get_line(void);
int token(char *line, char *av[]);
int env_builtin(void);
char *get_path(char *command);
#endif
