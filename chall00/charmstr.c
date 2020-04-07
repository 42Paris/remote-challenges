#include <unistd.h>

static int	my_ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	my_ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (!n)
		return (0);
	while ((s1[i] == s2[i]) && s1[i] && s2[i] && (i + 1 < n))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int ft_necklace(char *s1, char *s2)
{
	int len;
	int j;

	j = -1;
	len = my_ft_strlen(s1);
	if (my_ft_strlen(s2) != len)
		return (0);
	else if (!len)
		return (1);
	while (++j < len)
		if (s1[j] == s2[0] && !my_ft_strncmp(s1 + j, s2, len - j) \
				&& !my_ft_strncmp(s1, s2 + (len - j), j))
				return (1);
	return (0);
}
