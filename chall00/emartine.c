#include <string.h>
#include <stddef.h>
#include <stdlib.h>

int		ft_necklace(char *s1, char *s2)
{
	size_t len = strlen(s1);
	if (len != strlen(s2))
		return 0;
	char *buf = malloc(len * 2 + 1);
	strcpy(buf, s1);
	strcpy(buf + len, s1);
	return !!strstr(buf, s2);
}
