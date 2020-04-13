int	ft_check(int start, char *s1, char *s2)
{
	int i;
	int j;
	int k;

	j = 0;
	k = 0;
	i = start;
	while (s1[i] != '\0' && s2[j] != '\0')
	{
		if (s1[i] != s2[j])
			return (0);
		i++;
		j++;
	}
	if (s1[i] != '\0')
		return (0);
	while ((k < start) || s2[j] != '\0')
	{
		if (s1[k] != s2[j])
			return (0);
		k++;
		j++;
	}
	if ((s2[j] != '\0') || (k != start))
		return (0);
	return (1);
}

int	ft_necklace(char *s1, char *s2)
{
	int i;

	i = 0;
	if (s1 && s2)
	{
		if (s1[i] == '\0' && s2[i] == '\0')
			return (1);
		while (s1[i] != '\0' || s2[0] != '\0')
		{
			while (s1[i] != '\0')
			{
				if (s1[i] == s2[0])
					break;
				i++;
			}
			if (s1[i] == '\0')
				return (0);
			else if (ft_check(i, s1, s2) == 1)
				return (1);
			i++;
		}
	}
	return (0);
}
