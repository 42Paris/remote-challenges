#include <string.h>

int			ft_necklace(char *s1, char *s2)
{
	int		i = 1;
	int		len = (int)strlen(s1);

	if (len != strlen(s2))
		return (0);
	else if (len == 0 || !strcmp(s1, s2))
		return (1);
	while (i < len)
	{
		if (!strncmp(s1, &s2[len - i], i)
		&& !strncmp(&s1[i], s2, len - i))
			return (1);
		i++;
	}
	return (0);
}
