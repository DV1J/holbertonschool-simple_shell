#include "shell.h"

int main(void)
{
	char *input;
    char *av[2];

    while (1)
    {
        printf("$ ");

        input = get_line();

        if (input == NULL)
        {
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
