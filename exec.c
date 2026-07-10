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

	cpid = fork();

	if (cpid == -1)
	{
		perror("Fork unsucessful");
		return (-1);
	}
	else if (cpid == 0)
	{
		actual_command = get_path(*av);
		if (execve(actual_command, av, environ) == -1)
		{
			perror("Execve failed");
			return (127);
		}
	}
	else
	{
		wait(&finish);
	}
	return (0);
}
