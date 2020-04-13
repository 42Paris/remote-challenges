#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *add_char(char *ret, char c)
{
    int i;
    char *tmp;
    
    i = strlen(ret);
    tmp = malloc(i + 2);
    tmp[0] = c;
    tmp[i + 1] = 0;
    i--;
    while (ret[i])
    {
        tmp[i + 1] = ret[i];
        i--;
    }
    free(ret);
    return (tmp);
}
char *ft_rgb2hex(int r, int g, int b)
{
    char *base = "0123456789abcdef";
    char *ret;
     
    if (r > 255 | g > 255 | b > 255 | r < 0 | g < 0 | b < 0)
      return (NULL);
    ret = malloc(1);
    ret[0] = 0;
    while (b >= 0)
    {
        ret = add_char(ret, base[b % 16]);
        b /= 16;
        if (b == 0)
            b--;
    }
    if (strlen(ret) != 2)
        ret = add_char(ret, '0');
    while (g >= 0)
    {
        ret = add_char(ret, base[g % 16]);
        g /= 16;
        if (g == 0)
            g--;
    }
    if (strlen(ret) != 4)
        ret = add_char(ret, '0');
    while (r >= 0)
    {
        ret = add_char(ret, base[r % 16]);
        r /= 16;
        if (r == 0)
            r--;
    }
    if (strlen(ret) != 6)
        ret = add_char(ret, '0');
    ret = add_char(ret, '#');
    return (ret);
}
