#include <stdlib.h>
#include <string.h>

void	ccpy(char *buffer, size_t len)
{
	char c = buffer[0];
	for (size_t i = 0; i < len; i++)
		buffer[i] = buffer[i + 1];
	buffer[len] = c;
	buffer[len + 1] = '\0';
}

int ft_necklace(char *s1, char *s2)
{
	size_t	len = strlen((const char *)s1);
	size_t	len_s2 = strlen((const char *)s2);
	char	*buffer = (char *)malloc(len + 1);

	buffer = strcpy(buffer, (char *)s1);
	if (len == 0 && len_s2 == 0)
		return (1);
	for (size_t i = 0; i < len; i++)
	{
		ccpy(buffer, len - 1);
		if ((strcmp((const char *)buffer, (const char *)s2)) == 0)
			return (1);
	}
	return (0);
}
