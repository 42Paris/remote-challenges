#include <string.h>

void ft_shift(char *str)
{
    char head;
    size_t i;

    head = str[0];
    i = 1;
    while (str[i])
    {
        str[i - 1] = str[i];
        i++;
    }
    str[i - 1] = head;
}

int ft_necklace(char *s1, char *s2)
{
    size_t len;

    len = strlen(s1);
    if (len != strlen(s2))
        return 0;
    while (len--)
    {
        if (strcmp(s1, s2) == 0)
            return 1;
        ft_shift(s2);
    }
    return strcmp(s1, s2) == 0;
}
