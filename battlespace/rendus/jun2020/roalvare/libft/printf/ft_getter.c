/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <roalvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 22:32:35 by syndraum          #+#    #+#             */
/*   Updated: 2019/11/13 15:00:21 by roalvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag		get_flag(char c)
{
	const int	tab[] = {MINUS, ZERO, PLUS, HASH, SPACE, 0};
	int			i;

	i = -1;
	while (tab[++i] != 0)
		if (tab[i] == c)
			return (tab[i]);
	return (0);
}

t_type		get_type(char c)
{
	const int	tab[] = {'c', 's', 'p', 'i', 'd', 'u', 'x', 'X', '%', 0};
	int			i;

	i = -1;
	while (tab[++i] != 0)
		if (tab[i] == c)
			return (tab[i]);
	return (0);
}

t_lenght	get_lenght(char *s)
{
	if (!ft_strncmp(s, "ll", 2))
	{
		s += 2;
		return (LONG_LONG);
	}
	else if (!ft_strncmp(s, "hh", 2))
	{
		s += 2;
		return (CHAR);
	}
	else if (*s == 'l')
	{
		s++;
		return (LONG);
	}
	else if (*s == 'h')
	{
		s++;
		return (SHORT);
	}
	else
		return (NOTHING);
}
