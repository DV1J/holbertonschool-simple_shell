#include "shell.h"

int main(void)
{
	char *buffer = NULL;
	size_t buffersize = 0;
	ssize_t readline;

	while (1)
	{
		printf("$ ");
		fflush(stdout);

		readline = getline(&buffer, &buffersize, stdin);

		if (readline == -1)
		{
			break;
		}
		printf("%s", buffer);
	}
	free(buffer);
	return (0);
}
