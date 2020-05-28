/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:55:44 by roalvare          #+#    #+#             */
/*   Updated: 2019/10/09 14:52:23 by roalvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *copy;

	copy = NULL;
	if (!(copy = malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (copy);
	ft_strlcpy(copy, s1, (ft_strlen(s1) + 1));
	return (copy);
}
