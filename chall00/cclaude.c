#include <stdio.h>
#include <string.h>

int ft_necklace(char *s1, char *s2)
{
    int i;
    int len;

    if (!s1 || !s2 || strlen(s1) != strlen(s2))
        return (0);
    len = strlen(s1);
    if (len == 0)
        return (1);
    for (i = 0 ; i < len ; i++)
    {
        if (strncmp(s1, s2+i, len-i) == 0 && strncmp(s1+len-i, s2, i) == 0)
            return (1);
    }
    return (0);
}

// int main(void)
// {
//     printf("%d\n", ft_necklace("nicole", "nicole"));
//     printf("%d\n", ft_necklace("nicole", "icolen"));
//     printf("%d\n", ft_necklace("nicole", "lenico"));
//     printf("%d\n", ft_necklace("nicole", "coneli"));
//     printf("%d\n", ft_necklace("aabaaaaabaab", "aabaabaabaaa"));
//     printf("%d\n", ft_necklace("abc", "cba"));
//     printf("%d\n", ft_necklace("xxyyy", "xxxyy"));
//     printf("%d\n", ft_necklace("xyxxz", "xxyxz"));
//     printf("%d\n", ft_necklace("x", "x"));
//     printf("%d\n", ft_necklace("x", "xx"));
//     printf("%d\n", ft_necklace("x", ""));
//     printf("%d\n", ft_necklace("", ""));
//     return (0);
// }
