int ft_strlen(char *str)
{
    int i;
    
    i = 0;
    while (str[i])
        i++;
    return (i);
}


int ft_necklace(char *s1, char *s2)
{
    int i;
    int j;
    int k;
    int len;

    i = 0;
    j = 0;
    if ((len = ft_strlen(s1)) != ft_strlen(s2))
        return (0);
    if (len == 0)
        return (1);
    while (j < ft_strlen(s2))
    {
        k = 0;
        while (k < ft_strlen(s2) && s1[(i+k) % len] == s2[(j+k) % len])
        {
            k++;

        }
        if (k == len)
            return (1);
        j++;
    }
    return (0);
}