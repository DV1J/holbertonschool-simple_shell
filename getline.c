#include "shell.h"

char *get_line(void)
{
    char *buffer = NULL;
    size_t bufsize = 0;
    ssize_t characters;

    characters = getline(&buffer, &bufsize, stdin);
    
    if (characters == -1)
    {
        free(buffer);
        return NULL;
    }

    if (buffer[characters - 1] == '\n')
    {
        buffer[characters - 1] = '\0';
    }

    return buffer;
}
