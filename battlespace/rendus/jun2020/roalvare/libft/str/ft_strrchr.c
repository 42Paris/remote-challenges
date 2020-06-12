/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:57:43 by roalvare          #+#    #+#             */
/*   Updated: 2019/10/07 18:05:26 by roalvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*chaine;
	char	*pointeur;

	i = -1;
	chaine = (char*)s;
	pointeur = 0;
	while (chaine[++i])
	{
		if (s[i] == c)
			pointeur = (&chaine[i]);
	}
	if (chaine[i] == c)
		pointeur = (&chaine[i]);
	return (pointeur);
}
