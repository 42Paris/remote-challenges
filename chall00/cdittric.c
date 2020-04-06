#include <stdlib.h>

int ft_necklace(char *s1, char *s2)
{
    size_t  i;
    size_t  j;
    size_t  len;
    size_t  len2;

    len = 0;
    while (s1[len] != '\0')
        len++;
    len2 = 0;
    while (s2[len2] != '\0')
        len2++;
    if (len != len2)
        return (0);
    i = 0;
    while (i < len) {
        j = 0;
        while (s1[(i + j) % len] == s2[j])
            j++;
        if (j == len)
            return (1);
        i++;
    }
    return (len == 0 ? 1 : 0);
}
