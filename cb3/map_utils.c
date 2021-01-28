#include "cub3d.h"

char **free_memory(char **str)
{
    int i;

    i = 0;
    while(str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
    return (NULL);

}