/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phnguyen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 14:03:20 by phnguyen          #+#    #+#             */
/*   Updated: 2020/04/06 14:37:39 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int ft_strlen(const char *s1);
int	ft_strcmp(const char *s1, const char *s2);
void ft_charswap(char *s1);
char	*ft_strdup(const char *s1);
int ft_necklace(char *s1, char *s2);

int ft_strlen(const char *s1)
{
    int i;

    i = 0;
    while(s1[i])
        i++;
    return (i);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (((unsigned const char)*s1 - (unsigned const char)*s2) == 0)
		return (0);
	else if (((unsigned const char)*s1 - (unsigned const char)*s2) > 0)
		return (1);
	else
		return (-1);
}

void ft_charswap(char *s1)
{
    char c;

    c = s1[0];
    s1[0] = s1[ft_strlen(s1)];
    s1[ft_strlen(s1)] = c;
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*res;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	if ((res = (char*)malloc(sizeof(char) * (len + 1))))
	{
		while (s1[i])
		{
			res[i] = s1[i];
			i++;
		}
		res[i] = '\0';
		return (res);
	}
	return (NULL);
}

int ft_necklace(char *s1, char *s2)
{
    char *t1;
    char temp;
    int index;
    int found;

    if (ft_strlen(s1) != ft_strlen(s2))
        return (0);
    
    t1 = ft_strdup(s1);
    index = ft_strlen(s1);
    found = 0;
    while (index-- && found == 0)
    {
        if (ft_strcmp(t1, s2) == 0)
            found = 1;
        else
        {
            temp = t1[0];
            t1[0] = t1[ft_strlen(s1)];
            t1[ft_strlen(s1)] = temp;
        }
    }
    free(t1);
    return (found);
}