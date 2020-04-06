
static int	ft_strlen(char *s)
{
	char *d;

	d = s;
	while (*d)
		++d;
	return ((d - s));
}

static int	ft_strnequ(char *s1, char *s2, int n)
{
	if (!s1 || !s2)
		return (s1 == s2);
	while ((*s1 || *s2) && n--)
		if (*(s1++) != *(s2++))
			return (0);
	return (1);
}

int			ft_necklace(char *s1, char *s2)
{
	int len1;
	int len2;
	int i;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len1 != len2)
		return (0);
	if (len1 == 0)
		return (1);
	i = 0;
	while (i < len1)
	{
		if (ft_strnequ(s1, s2 + i, len1 - i)
			&& ft_strnequ(s1 + len1 - i, s2, i))
			return (1);
		++i;
	}
	return (0);
}
