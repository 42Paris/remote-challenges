# include <unistd.h>
# include <stdlib.h>

char	*ft_strnstr(char *s1, char *s2, int n)
{
	int i;
	int j;

	if (!s2[0])
		return ((char *)s1);
	i = 0;
	while (s1[i] && i < n)
	{
		j = 0;
		while (s2[j] == s1[i + j] && i + j < n)
		{
			if (s2[j + 1] == '\0')
			{
				return ((char *)s1 + i);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int ft_necklace(char *neck1, char*neck2)
{
	int i;
	int j;
	char *neck22;

	i = 0;
	j = 0;
	while (neck1[i])
		i++;
	while (neck2[j])
		j++;
	if (j != i)
		return (0);
	neck22 = malloc(sizeof(char) * ( i * 2 + 1));
	j = 0;
	while(neck2[j])
	{
		neck22[j] = neck2[j];
		j++;
	}
	j = 0;
	while(neck2[j])
	{
		neck22[i + j] = neck2[j];
		j++;
	}
	neck22[i + j] = '\0';
	if (!(ft_strnstr(neck22, neck1, i * 2)))
		return(0);
	return(1);
}
