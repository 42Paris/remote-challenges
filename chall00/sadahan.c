#include <string.h>

int         ft_necklace(char *s1, char *s2)
{
    int     i;
    int     i2;
    int     j;

    i = 0;
    if (!s1 && !s2)
        return (1);
    if (!s1 || !s2)
        return (0);
    if (strlen(s1) != strlen(s2))
        return (0);
    if (strcmp(s1, s2) == 0)
        return (1);
    i2 = 0;
    while (i2 < strlen(s2))
    {
        if (s1[0] == s2[i2])
        {
            j = i2;
            while (i < strlen(s1))
            {
                if (s1[i] != s2[j])
                    break;
                j++;
                if (j == strlen(s2))
                    j = 0;
                i++;
            }
            if (i == strlen(s1))
                return (1);
        }
        i2++;
    }
    return (0);
}
