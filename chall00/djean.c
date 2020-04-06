#include <stdbool.h>
#include <string.h>

bool cmp_with_offset(const char *s1, const char *s2, size_t offset)
{
	size_t len = strlen(s1);

	for (size_t i = 0; i < len; ++i)
	{
		if (s1[i] != s2[(i + offset) % len])
			return false;
	}
	return true;
}

int ft_necklace(char *s1, char *s2)
{
	size_t s1len;
	size_t s2len;

	if (s1 == NULL || s2 == NULL)
		return 0;

	s1len = strlen(s1);
	s2len = strlen(s2);

	if (s1len != s2len)
		return 0;

	if (s1len == 0 && s2len == 0)
		return 1;

	for (size_t i = 0; i < s1len; ++i)
	{
		if (cmp_with_offset(s1, s2, i))
			return 1;
	}

	return 0;
}
