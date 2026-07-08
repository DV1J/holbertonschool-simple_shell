#include "shell.h"

/**
 *get_line - Reads line of text typed by user
 *Return: Line typed || NULL if nothing was there
 */
char *get_line(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;
	ssize_t characters;

	characters = getline(&buffer, &bufsize, stdin);
	if (characters == -1)
	{
		free(buffer);
		return (NULL);
	}
	if (buffer[characters - 1] == '\n')
	{
		buffer[characters - 1] = '\0';
	}
	return (buffer);
}
