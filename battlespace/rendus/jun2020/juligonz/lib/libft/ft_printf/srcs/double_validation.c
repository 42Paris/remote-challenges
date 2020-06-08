/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 22:35:14 by juligonz          #+#    #+#             */
/*   Updated: 2019/12/12 17:34:01 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_width(t_manager *p, int nb_char)
{
	int	i;

	i = p->width;
	while (i > nb_char)
	{
		write_buffer(p, " ", 1);
		i--;
	}
}

static char	*get_error_float(long double n)
{
	if (n != n)
		return ("nan");
	if (n > FLT_MAX)
		return ("inf");
	else if (n < -FLT_MAX)
		return ("inf-");
	return (NULL);
}

int			is_valid_float(long double n, t_manager *p)
{
	int		nb_char;
	char	*error;

	error = get_error_float(n);
	if (!error)
		return (1);
	nb_char = (p->f.plus || error[3] == '-' ? 4 : 3);
	if (!p->f.dash || p->f.zero)
		put_width(p, nb_char);
	if (p->f.plus || error[3] == '-')
		write_buffer(p, (error[3] == '-' ? "-" : "+"), 1);
	write_buffer(p, error, 3);
	if (p->f.dash)
		put_double_width(p, nb_char);
	return (0);
}
