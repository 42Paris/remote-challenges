#include <string.h>

int	ft_necklace(char *s1, char *s2)
{
	int			i;
	int			size;
	int			offset;
	char		*substr;

	if (s1 == s2 || !strcmp(s1, s2))
		return (1);
	size = strlen(s1);
	if (size != strlen(s2) || !(substr = strchr(s2, s1[0])))
		return (0);
	while (i = -1, substr)
	{
		offset = substr - s2;
		while (++i < size)
			if (s1[i] != s2[(i + offset) % size])
				break;
		if (i == size)
			return (1);
		substr = strchr(substr + 1, s1[0]);
	}
	return (0);
}
