#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int ft_necklace(char *s1, char *s2)
{
	int		len_s1 = strlen(s1);
	int		len_s2 = strlen(s2);
	char	*cursor = s2;

	if (s1 == NULL || s2 == NULL)
		return (0);
	if (len_s1 != len_s2)
		return (0);
	char *cmp = NULL;
	if (!(cmp = calloc(1, len_s1)))
		return(0);
	while ((cursor = strchr(cursor, s1[0])))
	{
		strcpy(cmp, cursor);
		strncpy(cmp + strlen(cursor), s2, len_s2 - strlen(cursor));
		if (!strcmp(s1, cmp))
		{
			free(cmp);
			return(1);
		}
		cursor++;
	}
	free(cmp);
	return (0);
}
