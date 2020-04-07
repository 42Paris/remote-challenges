int len(char *s1)
{
    int i = -1;
    while  (s1[++i]);
    return (i);
}

int ncmp(char *s1, char *s2, unsigned int n)
{
	while  (*s1 == *s2 && s1++ && s2++ && n--);
	return (n ? *s1 - *s2 : 0);
}

int     cmp(char *a, char *b,long long l, long long f)
{
	return (!ncmp(a, b + f, l) && !ncmp(a + l, b, f) ? 1 : 0);
}

int		ft_necklace(char *s1, char *s2)
{
	int l,f;

	l = len(s1);
	if (s1 && len(s2) == l && (f = -1))
		while (++f <= l && !cmp(s1, s2, l - f, f));
	return (f < l ? 1 : s1=="" && s2=="" ? 1 : 0);
}