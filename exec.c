#include "shell.h"

/**
 *exec - forks a child process and executes a command
 *@av: array that contains the string of command
 *Return: -1 if fail
 */
int exec(char *av[])
{
	pid_t cpid;
	int finish;
	char *actual_command = NULL;

	actual_command = get_path(*av);
	if (actual_command == NULL)
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", *av);
		return (-1);
	}

	cpid = fork();

	if (cpid == -1)
	{
		perror("Fork unsucessful");
		return (-1);
	}
	else if (cpid == 0)
	{
		if (execve(actual_command, av, environ) == -1)
		{
			perror("Execve failed");
			free(actual_command);
			exit(127);
		}
	}
	else
	{
		wait(&finish);
		free(actual_command);
	}
	return (0);
}
