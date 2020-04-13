#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ft_necklace(char *s1, char *s2)
{
    char    *longstr1;
    int     i;

    if (!s1 || !s2)
        return (0);
    if (strlen(s1) != strlen(s2))
        return (0);
    if (!*s1 && !*s2)
        return (1);
    longstr1 = malloc(strlen(s1) + strlen(s1) + 1);
    strcpy(longstr1, s1);
    strcat(longstr1, s1);
    i = -1;
    while (++i < strlen(s1))
        if (!strncmp(longstr1 + i, s2, strlen(s1)))
        {
            free(longstr1);
            return (1);
        }
    free(longstr1);
    return (0);
}
