#include <stdlib.h>

int		ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dst, const char *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strcat(char *double_s1, const char *s1)
{
	int		i;
	int		j;

	i = ft_strlen(s1);
	j = 0;
	while (s1[j])
		double_s1[i++] = s1[j++];
	double_s1[i] = '\0';
	return (double_s1);
}

int		ft_verif(char *s, char c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;

	i = 0;
	if (*to_find == '\0')
		return (str);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == to_find[j])
		{
			j++;
			if (to_find[j] == '\0')
				return (&str[i]);
		}
		i++;
	}
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	if (!s1 || !s2)
		return (-1);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		++i;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int		ft_necklace(char *s1, char *s2)
{
	char	*double_s1;
	int		i;

	i = 0;
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	if ((ft_strcmp(s1, s2)) == 0)
		return (1);
	if (!(double_s1 = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s1) + 1)))
		return (0);
	ft_strcpy(double_s1, s1);
	ft_strcat(double_s1, s1);
	if ((ft_verif(double_s1, s2[i])))
	{
		if (ft_strstr(double_s1, s2))
		{
			free(double_s1);
			return (1);
		}
	}
	free(double_s1);
	return (0);
}
