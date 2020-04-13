int		ft_necklace(char *s1, char *s2)
{
	int i = 0;
	int k;
	int j;
	if (!*s1 && !*s2)
		return (1);
	if ((*s1 && !*s2) || (!*s1 && *s2))
		return (0);
	while (s1[i])
	{
		j = i;
		k = 0;
		while (s1[j] == s2[k] && s2[k])
		{
			k++;
			j++;
			if (s1[j] == 0)
				j = 0;
		}
		if (s2[k] == 0)
			return (1);
		i++;
	}
	return (0);
}
