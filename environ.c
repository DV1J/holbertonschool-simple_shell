#include <shell.h>

/**
 * env_builtin - prints the current environment
 *
 * Return: 0 on success
 */
int env_builtin(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return (0);
}
