#include <string.h>

int compare(int j, char *s1, char *s2)
{
	size_t i;
	
	i = -1;
	while (++i < strlen(s2))
	{
		if (s2[i] == '\0' || s1[i + j] == '\0')
			break;
		if (s2[i] != s1[j + i])
			return (0);
	}
	j = 0;
	while (i < strlen(s2))
		if (s2[i++] != s1[j++])
			return (0);
	return (1);
}

int ft_necklace(char *s1, char *s2)
{
	size_t i;

	i = -1;
	if (!s1 && !s2)
		return (1);
	if ((!s1 || !s2) || (strlen(s1) != strlen(s2)))
		return (0);
	while (++i < strlen(s1))
		if (s1[i] == s2[0])
			if (compare(i, s1, s2))
				return (1);
	return ((strlen(s1) == 0 && strlen(s2) == 0) ? 1 : 0);
}