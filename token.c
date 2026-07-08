#include "shell.h"
/**
 *token - splits a line of text into separate words
 *@line: input line
 *@av: array to pointers into line
 *Return: number of tokens found
*/
int token(char *line, char *av[])
{
	int i = 0;
	char *tok;

	tok = strtok(line, DELIM);
	while (tok != NULL && i < MAX_ARGS - 1)
	{
		av[i] = tok;
		i++;
		tok = strtok(NULL, DELIM);
	}
	av[i] = NULL;

	return (i);
}
