#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	if (!(s1) || !(s2))
		return (-1);
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

char	*ft_strdup(char *str)
{
	size_t	i;
	char	*newstr;

	i = 0;
	if (!(newstr = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (NULL);
	while (i < ft_strlen(str))
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

char	*move_right(char *s)
{
	int	n;
	int	i;
	char	tmp;

	i = 0;
	n = ft_strlen(s);
	tmp = s[0];
	while (i < n)
	{
		s[i] = s[i+1];
		i++;
	}
	s[i - 1] = tmp;
	return (s);
}

int	ft_necklace(char *s1, char *s2)
{
	int	n;
	char	*str;

	n = ft_strlen(s1);
	if (!s1 && !s2 || (s1 == "" && s2 == ""))
		return (1);
	if ((s1 && !s2) || (!s1 && s2))
		return (0);
	if (n != ft_strlen(s2))
		return (0);
	str = ft_strdup(s1);
	while(n)
	{
		if (!(ft_strcmp(move_right(str), s2)))
		{
			free(str);
			return (1);
		}
		n--;
	}
	free(str);
	return (0);
}
