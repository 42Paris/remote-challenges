#include <string.h>
#include <stdio.h>

int compare(char *s1, char *s2, unsigned int swaps, unsigned int len)
{
	s1 += swaps;
	if (len == 0)
		return (0);
	if (strncmp(s1, s2, len - swaps) != 0)
		return (1);
	s1 -= swaps;
	s2 += len - swaps;
	if (swaps == 0)
		return (0);
	if (swaps == 0 || strncmp(s1, s2, swaps) != 0)
		return (1);
	return (0);
}

int ft_necklace(char *s1, char *s2)
{
	unsigned int swaps;
	unsigned int len;

	len = strlen(s1);
	swaps = 0;
	if (len != strlen(s2))
		return (0);
	while (swaps <= len)
	{
		if (compare(s1, s2, swaps, len) == 0)
			return (1);
		swaps++;
	}
	return (0);
}