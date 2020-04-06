int		ft_necklace(char *s1, char *s2)
{
	int i = 0;
	int j = 0;
	int tab[256] = {};
	int k = 255;

	while (k > 0)
	{
		tab[k] = 0;
		k--;
	}
	while(s1[j])
	{
		tab[(int)s1[j]] = tab[(int)s1[j]] + 1;
		j++;
	}
	while(s2[i])
	{
		tab[(int)s2[i]] = tab[(int)s2[i]] - 1;
		i++;
	}
	while (k < 256)
	{
		printf("%d\n", tab[k]);
		if (tab[k] != 0)
			return (0);
		k++;
	}
	return (1);
}
