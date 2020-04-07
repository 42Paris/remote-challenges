#include <string.h>

void	slide_pearl(char *str)
{
	char	tmp;
	int		i;

	i = 0;
	tmp = str[0];
	while (str[i] && str[i + 1])
	{
		str[i] = str[i + 1];
		i++;
	}
	str[i] = tmp;
}

int		ft_necklace(char *s1, char *s2)
{
	int	i;
	int	diff;

	i = 0;
	if (strlen(s1) != strlen(s2))
		return (0);
	if (!s1[0] && !s2[0])
		return (1);
	while (s1[i])
	{
		slide_pearl(s2);
		diff = strcmp(s1, s2);
		if (diff == 0)
			return (1);
		i++;
	}
	return (0);
}
