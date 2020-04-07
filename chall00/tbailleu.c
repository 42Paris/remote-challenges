#include <string.h>

int		ft_necklace(char *s1, char *s2)
{
	long long len;
	long long offset;

	if (s1 && s2)
	{
		len = strlen(s1);
		if (strlen(s2) == len)
		{
			offset = -1;
			while (++offset <= len)
			{
				if (strncmp(s1, s2 + offset, len - offset) == 0)
					if (strncmp(s1 + len - offset, s2, offset) == 0)
						return (1);
			}
		}
	}
	return (0);
}
