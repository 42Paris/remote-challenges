/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:17:51 by roalvare          #+#    #+#             */
/*   Updated: 2019/10/07 17:56:29 by roalvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*chaine;

	i = -1;
	chaine = (char*)s;
	while (chaine[++i])
	{
		if (chaine[i] == c)
			return (&chaine[i]);
	}
	if (chaine[i] == c)
		return (&chaine[i]);
	return (0);
}
