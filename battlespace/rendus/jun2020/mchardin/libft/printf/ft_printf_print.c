/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <mchardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 15:25:55 by mchardin          #+#    #+#             */
/*   Updated: 2020/03/02 15:47:56 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_delcontent(void *cont)
{
	t_cont	*temp_cont;

	temp_cont = cont;
	ft_freez((void **)&temp_cont->str);
	ft_freez((void **)&temp_cont);
}

int		ft_print_lst(int fd, t_list *lst)
{
	t_list	*start;
	t_cont	*cont;
	int		len;

	len = 0;
	start = lst;
	while (lst)
	{
		cont = lst->content;
		len += ft_len_c(cont->str, 0);
		if (cont->czero == 2 || cont->czero == 4)
			ft_putchar_fd(0, fd);
		if (cont->czero > 0 && ft_len_c(cont->str, 0) > 1)
			ft_putstr_fd(&cont->str[1], fd);
		if (cont->czero == 1 || cont->czero == 2)
			len += 1;
		if (cont->czero == 1 || cont->czero == 3)
			ft_putchar_fd(0, fd);
		if (cont->czero == 0)
			ft_putstr_fd(cont->str, fd);
		lst = lst->next;
	}
	ft_lstclear(&start, &ft_delcontent);
	return (len);
}
