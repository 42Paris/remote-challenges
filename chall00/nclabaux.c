int ft_strlen(char *s)
{
	int size;

	size = 0;
	while (s[size])
		size++;
	return (size);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 != 0)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int ft_necklace(char *s1, char *s2)
{
	int len1;
	int len2;
	int	i;
	int	no_occurence;
	int shift;
	int end_reached;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len1 != len2)
		return (0);
	if (!ft_strcmp(s1, s2))
		return (1);
	shift = 0;
	end_reached = 0;
	no_occurence = 1;
	while (s2[shift])
	{
		while (no_occurence && shift < len2)
		{
			if (s2[shift] == s1[0])
				no_occurence = 0;
			else
				shift++;
		}
		if (no_occurence)
			return (0);
		i = 0;
		while (s1[i] && s2[i + shift - len2 * end_reached] && s1[i] == s2[i + shift - len2 * end_reached])
		{
			i++;
			if (i + shift == len2)
				end_reached = 1;
		}
		if (i == len1)
			return (1);
		shift++;
	}
	return (0);
}