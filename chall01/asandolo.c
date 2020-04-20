#include <stdlib.h>
#include <string.h>
//
// Created by Alexandre SANDOLO on 13/04/2020.
//

void	convert2(char *str, char c)
{
    int i = 0;
    while (str[i])
        i++;
    str[i] = c;
    str[i + 1] = '\0';
}

void	convert(char *str, int n)
{
    char *base = "0123456789abcdef";
    if (n / 16)
    {
        convert(str, n / 16);
        convert(str, n % 16);
    }
    else
        convert2(str, base[n]);
}

void    add_zero(char *s)
{
    char c = s[0];
    s[0] = '0';
    s[1] = c;
    s[3] = '\0';
}
void    ft_free(char *a, char *b, char *c)
{
    free(a);
    free(b);
    free(c);
}

int  ft_check(int r, int g, int b)
{
    if(r < 0 || r > 255)
        return (0);
    if(g < 0 || g > 255)
        return (0);
    if(b < 0 || b > 255)
        return (0);
    return (1);
}

char *ft_rgb2hex(int r, int g, int b)
{
    if(!ft_check(r,g,b))
        return (NULL);
    char *rh = malloc(sizeof(char) * 3);
    char *gh = malloc(sizeof(char) * 3);
    char *bh = malloc(sizeof(char) * 3);
    char *ret = malloc(sizeof(char *) * 3 + 1);

    convert(rh, r);
    if (strlen(rh) == 1)
        add_zero(rh);
    convert(gh, g);
    if (strlen(gh) == 1)
        add_zero(gh);
    convert(bh, b);
    if (strlen(bh) == 1)
        add_zero(bh);
    strcpy(ret, "#");
    ret = strcat(ret, rh);
    ret = strcat(ret, gh);
    ret = strcat(ret, bh);
    ft_free(rh, gh, bh);
    return (ret);
}