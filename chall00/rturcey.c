#include <stdlib.h>

int     ft_strlen(char *s)
{
    int     i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

int     ft_strcmp(char *s1, char *s2)
{
    int     i;

    i = -1;
    while (s1[++i])
        if (s1[i] != s2[i])
            return (-1);
    return (0);
}

char    *ft_reverse(char *s)
{
    char    *str;
    int     i;

    i = 0;
    if (!(str = malloc(ft_strlen(s) + 1)))
        return (NULL);
    while (++i < ft_strlen(s))
        str[i - 1] = s[i];
    str[i - 1] = s[0];
    str[i] = '\0';
    free(s);
    return (str);
}

int     ft_check(char *s1, char *s2)
{
    int     i;
    int     j;

    if (!s1 || !s2 || (ft_strlen(s1) != ft_strlen(s2)))
        return (1);
    i = -1;
    while (++i < ft_strlen(s1))
    {
        j = -1;
        while (++j < ft_strlen(s2))
        {
            if (s1[i] == s2[j])
                break;
            else if (j == ft_strlen(s2) - 1)
                return (1);
        }
    }
    return (0);
}

int     ft_necklace(char *s1, char *s2)
{
    int     i;
    char    *str;

    i = -1;
    if (ft_check(s1, s2) != 0)
        return (0);
    if (ft_strlen(s1) == 0 && s1[0] == '\0' && s2[0] == '\0')
        return (1);
    if (!(str = malloc(ft_strlen(s1) + 1)))
        return (-1);
    while (++i < ft_strlen(s1))
        str[i] = s1[i];
    i = -1;
    while (++i < ft_strlen(s1))
    {
        if (ft_strcmp(str, s2) == 0)
            return (1);
        if (!(str = ft_reverse(str)))
            return (-1);
    }
    free (str);
    return (0);
}
