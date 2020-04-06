
int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int			i;
	unsigned char	*c_s1;
	unsigned char	*c_s2;

	c_s1 = (unsigned char *)s1;
	c_s2 = (unsigned char *)s2;
	i = 0;
	if (!c_s1 && !c_s2)
		return (0);
	while (i < n)
	{
		if (c_s1[i] != c_s2[i])
			return (c_s1[i] - c_s2[i]);
		i++;
	}
	return (0);
}

int ft_strlen(char *s)
{
	int len;

	len = 0;
	while (s[len])
		len++;
	return(len);
}


int ft_necklace(char *s1, char *s2)
{
	int i;
	int j;
	char cp[ft_strlen(s1) + 1];
	int start;

	i = 1;
	if (ft_strlen(s1) != ft_strlen(s2))
		return(0);
	if (ft_strncmp(s1, s2, ft_strlen(s1)) == 0)
			return(1);
	while (i < ft_strlen(s1))
	{
		start = i;
		j = 0;
		while (start < ft_strlen(s1))
			cp[j++] = s1[start++];
		start = 0;
		while (start < i)
			cp[j++] = s1[start++];
		cp[j] = '\0';
		if (ft_strncmp(s2, cp, ft_strlen(s1)) == 0)
			return(1);
		i++;
	}
	return(0);
}

