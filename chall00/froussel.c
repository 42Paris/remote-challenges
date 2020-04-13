#include <string.h>
#include <stdlib.h>

char	*ft_strjoin(char const *str1, char const *str2)
{
	char	*res;
	char	*beg;
	int		len;

	if (!str1 && !str2)
		return (0);
	len = 0;
	if (str1)
		len = strlen(str1);
	if (str2)
		len += strlen(str2);
	if (!(res = malloc(sizeof(*res) * (len + 1))))
		return (0);
	beg = res;
	if (str1)
		while (*str1)
			*res++ = *str1++;
	if (str2)
		while (*str2)
			*res++ = *str2++;
	*res = '\0';
	return (beg);
}

int		ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	x;

	i = 0;
	if (!*to_find)
		return (1);
	while (str[i] && i < len)
	{
		j = i;
		x = 0;
		while (str[j] == to_find[x] && j < len)
		{
			if (to_find[x + 1] == '\0')
				return (1);
			j++;
			x++;
		}
		i++;
	}
	return (0);
}

int ft_necklace(char *s1, char *s2)
{
	char	*tmp;
	int		ret;

	if (!s1 || !s2)
		return (0);
	if (strlen(s1) != strlen(s2))
		return (0);
	if (!(tmp = ft_strjoin(s1, s1)))
		return (0);
	ret = ft_strnstr(tmp, s2, strlen(tmp));
	free(tmp);
	return (ret);
}
