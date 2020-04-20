int ft_strlen(char* s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i += 1;
	return(i);
}

char *rotate(char* s)
{
	char c = s[0];
	for(int i = 0; i < ft_strlen(s); ++i)
		s[i] = s[i+1];
	s[ft_strlen(s)-1] = c;
	return(s);
}

int is_eq(char* s1, char* s2)
{
	for(int i = 0; i < ft_strlen(s1); ++i)
	{
		if(s1[i] == s2[i])
			continue;
		else
			return(0);
	}
	return(1);
}

int ft_necklace(char* s1, char* s2)
{
	int res = 0;

	if (ft_strlen(s1) == ft_strlen(s2))
	{
		if (ft_strlen(s1) == 0)
			return(1);
		for (int i = 0; i < ft_strlen(s1); ++i)
		{
			s2 = rotate(s2);
			if (is_eq(s1, s2))
				res = 1;
		}
	}
	else
		res = 0;
	return(res);
}
