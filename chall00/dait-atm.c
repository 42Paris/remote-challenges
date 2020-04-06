#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		ft_strncmp(char const *s1, char const *s2, size_t n)
{
	int res;

	if (!n)
		return (0);
	while ((*s1) && (*s2) && (*s1 == *s2) && --n)
	{
		s1++;
		s2++;
	}
	res = (unsigned char)*s1 - (unsigned char)*s2;
	return (res);
}

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;

	i = 0;
	while (len)
	{
		if (!src[i])
		{
			while (len--)
				dst[i++] = '\0';
			break ;
		}
		dst[i] = src[i];
		i++;
		len--;
	}
	return (dst);
}

int		ft_necklace(char *s1, char *s2)
{
	char	dbl[ft_strlen(s2) * 2];
	size_t	dbl_len;
	size_t	i;

	if (!s1 || !s2 || ft_strlen(s1) != ft_strlen(s2))
		return (0);
	dbl_len = ft_strlen(s2);
	if (!strncmp(s1, s2, dbl_len))
		return (1);
	i = 0;
	ft_strncpy(dbl, s2, dbl_len);
	ft_strncpy(dbl + dbl_len, s2, dbl_len);
	while (i < dbl_len)
	{
		if (!(ft_strncmp(dbl + i, s1, dbl_len)))
			return (1);
		i++;
	}
	return (0);
}
