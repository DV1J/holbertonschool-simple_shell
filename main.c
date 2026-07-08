#include "shell.h"

int main(void)
{
	char *input;
    char *av[2];
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

		av[0] = input;
        av[1] = NULL;
        exec(av);

        free(input);
    }

    return (0);
}
