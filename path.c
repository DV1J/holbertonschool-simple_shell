#include "shell.h"

/**
 *_getenv_path - finds the PATH variable in the environment
 *
 *Return: pointer to the value of PATH, or NULL if not found
 */
char *_getenv_path(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
			return (environ[i] + 5);
		i++;
	}
	return (NULL);
}

/**
 * get_path - looks for full path of a command by looking for path
 * @command: command to look for
 * Return: path if found || NULL if not found
 */
char *get_path(char *command)
{
	char *path_env = NULL, *path_copy = NULL, *dir = NULL, *full_path = NULL;
	struct stat buffer;

	if (!command)
		return (NULL);

	if (strchr(command, '/') != NULL)
	{
		if (stat(command, &buffer) == 0)
			return (strdup(command));
		return (NULL);
	}
	path_env = _getenv_path();
	if (!path_env)
		return (NULL);

	path_copy = strdup(path_env);
	if (!path_copy)
		return (NULL);

	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		full_path = malloc(strlen(dir) + strlen(command) + 2);
		if (!full_path)
		{
			free(path_copy);
			return (NULL);
		}
		sprintf(full_path, "%s/%s", dir, command);
		if (stat(full_path, &buffer) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
