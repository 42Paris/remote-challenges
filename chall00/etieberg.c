#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ft_necklace(char *s1, char *s2)
{
	unsigned long i;
	char *dest;
	
	if (!(dest = (char*)malloc(sizeof(char) * strlen(s1)+1)))
		exit(0);
	if (!strcmp(s1, "") && !strcmp(s2, ""))
		return (1);
	if (strlen(s1) != strlen(s2))
		return (0);
	i = -1;
	memcpy(dest, s1, strlen(s1)+1);
	while (++i < strlen(s1))
	{
		strncat(dest, &s1[i], 1);
		if (!strcmp(dest+i+1, s2))
		{
			free(dest);
			return (1);
		}
	}
	free(dest);
	return (0);
}
