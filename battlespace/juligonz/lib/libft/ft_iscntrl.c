/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iscntrl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 09:25:10 by juligonz          #+#    #+#             */
/*   Updated: 2019/09/13 09:27:37 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iscntrl(int c)
{
	return ((c >= 0 && c <= 31) || c == 127);
}
