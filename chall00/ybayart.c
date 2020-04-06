#include <stdlib.h>

size_t	ft_strlen(char *str) {
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

char	*ft_strdup(const char *src)
{
	int		i;
	int		len;
	char	*ptr;

	i = 0;
	len = ft_strlen((char*)src);
	if ((ptr = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	while (i < len)
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}


char	*ft_strcpy(char *dst, char const *src)
{
	size_t i;

	i = -1;
	if (dst == NULL || src == NULL)
		return (NULL);
	while (src[++i])
		dst[i] = src[i];
	dst[i] = '\0';
	return (dst);
}

int		ft_necklace(char *s1, char *s2) {
	size_t	len1;
	size_t	len2;
	size_t	i;
	char	*str;

	len1 = ft_strlen(s1);
	if (len1 != (len2 = ft_strlen(s2)) || len1 == 0 || len2 == 0)
		return (0);
	i = 0;
	if ((str = ft_strdup(s1)) == NULL)
		return (0);
	while (i < len1)
	{
		if (ft_strcmp(str, s2) == 0)
		{
			free(str);
			return (1);
		}
		ft_strcpy(str, str + 1);
		str[len1 - 1] = s1[i];
		str[len1] = '\0';
		i++;
	}
	free(str);
	return (0);
}
