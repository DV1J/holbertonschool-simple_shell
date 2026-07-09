#include "shell.h"


char *handle_path(char *input)
{
	struct stat path;
	char *path_env = NULL;
	char *path_copy, *folder, *full_path;
	int i = 0;

	if (stat(input, &path) == 0)
	{
		return (strdup(input));
	}
	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], "path=", 5) == 0)
			path_env = environ[i] + 5;
		break;
	}
	i++;
}
