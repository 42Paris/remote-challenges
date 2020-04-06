#include <stdio.h>

int ft_strlen(char *s)
{
    int i;
    
    i = 0;
    while (s && s[i])
        i++;
    return (i);
}

int ft_necklace(char *s1, char *s2)
{
    int len;
    int i;
    int j;
    
    if (!s1 || !s2 || !(ft_strlen(s1) == ft_strlen(s2)))
        return (0);
    len = ft_strlen(s1);
    i = 0;
    while (i < len)
    {
        j = 0;
        while (j < len && s1[j] == s2[(i + j) % len])
            j++;
        if (j == len)
            return (1);
        i++;
    }
    return (0);
}
