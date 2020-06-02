/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <mchardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 12:22:55 by mchardin          #+#    #+#             */
/*   Updated: 2019/12/07 15:55:09 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "libft.h"

static int		lst_len_p(t_list *lst)
{
	int		len;
	t_cont	*cont;

	len = 0;
	while (lst)
	{
		cont = lst->content;
		len += ft_len_c(cont->str, 0);
		lst = lst->next;
	}
	return (len);
}

static char		*ft_printf_str(t_list *lst)
{
	t_list	*start;
	t_cont	*cont;
	char	*str;
	int		i;
	int		j;

	i = 0;
	if (!(str = malloc(sizeof(char) * (lst_len_p(lst) + 1))))
		return (0);
	start = lst;
	while (lst)
	{
		cont = lst->content;
		j = 0;
		while (cont->str[j])
		{
			str[i] = cont->str[j];
			i++;
			j++;
		}
		lst = lst->next;
	}
	str[i] = 0;
	ft_lstclear(&start, &ft_delcontent);
	return (str);
}

char			*ft_sprintf(const char *str, ...)
{
	t_list	*lst;
	va_list	ap;

	lst = 0;
	va_start(ap, str);
	if (!(ft_str(str, &lst, &ap)))
	{
		ft_lstclear(&lst, &ft_delcontent);
		return (0);
	}
	va_end(ap);
	return (ft_printf_str(lst));
}

int				ft_dprintf(int fd, const char *str, ...)
{
	t_list	*lst;
	va_list	ap;

	lst = 0;
	va_start(ap, str);
	if (!(ft_str(str, &lst, &ap)))
	{
		ft_lstclear(&lst, &ft_delcontent);
		return (-1);
	}
	va_end(ap);
	return (ft_print_lst(fd, lst));
}
