#include <stdlib.h>
#include <stdio.h>


int ft_necklace(char *s1, char *s2)
{
    int i;
    int j;
    int len1;
    int len2;
    int match;

    len1 = 0;
    while (s1[len1] != '\0')
        len1++;

    len2 = 0;
    while (s2[len2] != '\0')
        len2++;

    if (len1 != len2)
        return (0);
    
    if (len1 == 0)
        return (1);
    
    i = 0;
    while (i < len1)
    {
        j = 0;
        match = 1;
        while (j < len2)
        {
            if (s1[j] != s2[(i + j) % len2]) {
                match = 0;
                break;
            }
            j++;
        }
        if (match)
            return (1);
        i++;
    }
    return (0);
}
