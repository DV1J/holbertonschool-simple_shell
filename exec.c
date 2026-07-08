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
	extern char **environ;

	cpid = fork();

	if (cpid == -1) 
	{
		perror("Fork unsucessful"); 
		return -1;
	}
	else if (cpid == 0)
	{
		if (execve(av[0], av, environ) == -1)
		{
			perror("Execve failed");
			return -1; 
		}
	}
	else
	{
		wait(&finish);
	}
	return 0;
}
