/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyrlemai.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrlemai <cyrlemai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 15:46:30 by cyrlemai          #+#    #+#             */
/*   Updated: 2020/04/06 16:03:42 by cyrlemai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

int	ft_necklace(const char *start, const char *end)
{
	char	*rotation;
	char	tmp;
	size_t	start_len;
	size_t	i;
	int		res;

	start_len = strlen(start);
	if (start_len != strlen(end))
		return (0);
	if (strcmp(start, end) == 0)
		return (1);
	res = 0;
	rotation = strdup(start);
	do
	{
		tmp = rotation[0];
		for (i = 0; i + 1 < start_len; ++i)
			rotation[i] = rotation[i + 1];
		rotation[i] = tmp;
		res = (strcmp(end, rotation) == 0);
	} while (!(res || strcmp(start, rotation) == 0));
	free(rotation);
	return (res);
}
