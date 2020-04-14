#include <stdlib.h>
#include <stdio.h>

char *ft_rgb2hex(int r, int g, int b)
{
    char *s;

    s = malloc(8 * sizeof(char));
    sprintf(s, "#%02x%02x%02x", r, g, b);
    return s;
}
