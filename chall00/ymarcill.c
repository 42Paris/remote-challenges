#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int	ft_necklace(char *s1, char *s2)
{
	int	i;
	int	y;
	int	savey;
	int	savex;
	int	nb;
	int	check;

	i = 0;
	y = 0;
	nb = 0;
	savex = 0;
	check = 0;
	if (strlen(s2) != strlen(s1))
		return (0);
	if (!s1[0] && !s2[0])
		return (1);
	while (s1[i] && s2[y])
	{
		check++;
		if (s1[i] == s2[y])
		{
			savey = y;
			nb = 0;
			while ((s1[i] && s2[y]) ||  y < savex)
			{
				if (s1[i] != s2[y])
				{
					nb = 1;
					i = 0;
					break ;
				}
				y++;
				i++;
			}
			if (nb != 1 && (y == savex ||  i == y))
				return (1);
			else if ((nb == 1 && check >= strlen(s2)))
				return (0);
			savex = savey;
			if (y == strlen(s2))
				y = -1;
			else
				y--;
		}
		y++;
	}
	return (0);
}
