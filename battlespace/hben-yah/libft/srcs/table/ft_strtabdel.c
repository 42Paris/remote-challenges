/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtabdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 14:34:52 by hben-yah          #+#    #+#             */
/*   Updated: 2019/02/08 20:32:39 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strtabdel(char ***tab)
{
	ft_tabdel((void ***)tab);
}

void	ft_strtabdel2(char ***tab1, char ***tab2)
{
	ft_tabdel2((void ***)tab1, (void ***)tab2);
}

void	ft_strtabdel3(char ***tab1, char ***tab2, char ***tab3)
{
	ft_tabdel3((void ***)tab1, (void ***)tab2, (void ***)tab3);
}

void	ft_strtabdel4(char ***t1, char ***t2, char ***t3, char ***t4)
{
	ft_tabdel4((void ***)t1, (void ***)t2, (void ***)t3, (void ***)t4);
}
