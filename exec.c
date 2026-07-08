#include "shell.h"

/**
 *exec - forks a child process and executes a command
 *@av: array that contains the string of command
 *Return: -1 if fail
 */
int exec(char *av[])
{
	pid_t cpid; //child PID//
	int finish;
	extern char **environ;

	cpid = fork(); //creating Child process using fork()// 

	if (cpid == -1) // check if fork failed//
	{
		perror("Fork unsucessful"); //print error message//
		return -1;
	}
	else if (cpid == 0) //this code only run inside the child process//
	{
		if (execve(av[0], av, environ) == -1) //if running the command fails//
		{
			perror("Execve failed"); //print the system error message//
			return -1; //return error//
		}
	}
	else
	{
		wait(&finish); //waiting for child process to finish//
	}
	return 0;
}
