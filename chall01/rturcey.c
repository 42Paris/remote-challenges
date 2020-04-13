#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

char    *rollon(const char *format, ...)
{
    int     i;
    char    *s;
    
    s = NULL;
    i = 0;
    va_list ap;

    va_start(ap, format);
    if ((i = vasprintf(&s, format, ap)) == -1)
    {
        va_end(ap);
        return (NULL);
    }
    va_end(ap);
    return (s);
}

char    *ft_rgb2hex(int r, int g, int b)
{
    int     col[3];
    int     i;
    
    col[0] = r;
    col[1] = g;
    col[2] = b;
    i = -1;
    while (++i < 3)
        if (col[i] < 0 || col[i] > 255)
            return (NULL);
    return (rollon("#%02x%02x%02x", r, g, b));
}