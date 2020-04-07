#include <string.h>
#include <stdlib.h>

static int	ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

static char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	*ft_strncat(char *s1, const char *s2, int n)
{
	int		i;
	int		j;

	i = 0;;
	j = 0;
	
	while (s1[i])
		i++;
	while (j < n && s2[j])
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}

static int	ft_slide(char *s1, char *s2)
{
	char	*tmp;
	int		i;

	if (!(tmp = (char *)malloc(sizeof(char) * (ft_strlen(s2) + 1))))
		return (0);
	i = 0;
	while (i < ft_strlen(s1))
	{
		tmp = ft_strncat(ft_strcpy(tmp, s2 + i), s2, i);
		if (ft_strcmp(s1, tmp) == 0)
		{
			free(tmp);
			tmp = NULL;
			return (1);
		}
		i++;
	}
	free(tmp);
	tmp = NULL;
	return (0);
}

int			ft_necklace(char *s1, char *s2)
{
	if (!s1 || !s2)
	{
		if (!s1 && !s2)
			return (1);
		return (0);
	}
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	if (ft_strcmp(s1, s2) == 0)
		return (1);
	else if (ft_slide(s1, s2) == 0)
		return (0);
	return (1);
}
