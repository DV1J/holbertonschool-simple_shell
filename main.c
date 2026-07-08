#include "shell.h"

int main(void)
{
	char *input;
	char *av[MAX_ARGS];
	int inter = isatty (STDIN_FILENO);

    while (1)
    {
		if (inter)
			printf("$ ");

        input = get_line();

        if (input == NULL)
        {
            if (inter)
                printf("\nExiting shell...\n");
            break;
        }
        if (strcmp(input, "exit") == 0)
        {
            free(input); 
            break;
        }

		if (token(input, av) == 0)
		{
			free(input);
			continue;
		}

		if (strcmp(av[0], "exit") == 0)
		{
			free(input);
			break;
		}
        exec(av);

        free(input);
    }

    return (0);
}
