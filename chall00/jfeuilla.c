int ft_necklace(char *s1, char *s2)
{
	int i;
	int	j;
	int len;
	int save;

	i = 0;
	while (s1[i])
	{
		j = 0;
		if (s1[i] == s2[j])
		{
			save = i;
			len = 0;
			while (s2[j] && s1[i] && s1[i] == s2[j])
			{
				i++;
				j++;
				if (s1[i] == 0)
					i = 0;
				if (s2[j] != 0)
					len++;
			}
			if (len == j)
				return (1);
			i = save;
		}
		i++;
	}
	return (0);
}
