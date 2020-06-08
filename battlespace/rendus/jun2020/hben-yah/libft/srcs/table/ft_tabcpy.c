/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 17:53:32 by hben-yah          #+#    #+#             */
/*   Updated: 2019/02/08 20:32:30 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	**ft_tabcpy(void **dst, void **src)
{
	void **d;

	d = dst;
	while (*src)
		*(d++) = *(src++);
	*d = (void *)*src;
	return (dst);
}

char	**ft_strtabcpy(char **dst, char **src)
{
	return ((char **)ft_tabcpy((void **)dst, (void **)src));
}
