#include <stdlib.h>
#include <string.h>

static int ft_firstcheck(char *s1, char *s2, size_t len1, size_t len2)
{
    if (len1 == 0 && len2 == 0)
        return (1);
    if (strcmp(s1, s2) == 0)
        return (1);
    return (0);
}

static char *ft_movestr(char *s, size_t len)
{
    int i = 1;
    int j = 0;
    char c = s[0];
    char *nstr = malloc(sizeof(char *) * 6);


    while (s[i])
    {
        nstr[i - 1] = s[i];
        i++;
    }
    nstr[len - 1] = c;
    free(s);
    return (nstr);
}

int ft_necklace(char *s1, char *s2)
{
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);
    size_t i = 0;
    char *tmp = strdup(s2);

    if (len1 == len2)
    {
        if (ft_firstcheck(s1, s2, len1, len2))
        {
            free(tmp);
            return (1);
        }
        while (i < len2)
        {
            tmp = ft_movestr(tmp, len2);
            if (strcmp(s1, tmp) == 0)
            {
                free(tmp);
                return (1);
            }
            i++;
        }
    }
    free(tmp);
    return (0);
}
