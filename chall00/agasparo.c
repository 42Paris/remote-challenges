int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int ft_cmp(int index, char *s1, char *s2)
{
	int i;

	i = 0;
	while (i < ft_strlen(s2)) {
		if (s2[i] == '\0' || s1[i + index] == '\0')
			break;
		if (s2[i] != s1[index + i])
			return (0);
		i++;
	}
	index = 0;
	while (i < ft_strlen(s2))
	{
		if (s2[i] != s1[index])
			return (0);
		index++;
		i++;
	}
	return (1);
}

int ft_necklace(char *s1, char *s2)
{
	int i;

	i = 0;
	if (!s1 && !s2)
		return (1);
	if (!s1 ||!s2)
		return (0);
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	while (i < ft_strlen(s1)) {

		if (s1[i] == s2[0]) {
			if (ft_cmp(i, s1, s2))
				return (1);
		}
		i++;
	}
	if (ft_strlen(s1) == 0 && ft_strlen(s2) == 0)
		return (1);
	return (0);
}