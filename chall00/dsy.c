#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	rot_strcmp(char *s1, char *s2, size_t rot, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[(rot+i) % n])
			return (0);
		i++;
	}
	return (1);
}


int     ft_necklace(char *s1, char *s2)
{
	int     n;
	int	rot;

	rot = 0;
	n = ft_strlen(s1);
	if (!s1 && !s2 || (s1 == "" && s2 == ""))
		return (1);
	if ((s1 && !s2) || (!s1 && s2))
		return (0);
	if (n != ft_strlen(s2))
		return (0);
	while (rot < n)
	{
		if (rot_strcmp(s1, s2, rot, n))
			return (1);
		rot++;
	}
	return (0);
}
