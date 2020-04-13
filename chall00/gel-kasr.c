
#include <string.h>

int	ft_necklace(char *s1, char *s2)
{
	size_t	i;
	size_t	len;
	size_t	n;

	if (!s1 || !s2)
		return (!s1 && !s2);
	len = strlen(s1);
	if (len != strlen(s2))
		return (0);
	if (!len)
		return (1);
	i = 0;
	while (s1[i])
	{
		n = 0;
		while (s1[(i + n) % len] == s2[n])
			n++;
		if (n == len)
			return (1);
		i++;
	}
	return (0);
}
