/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <roalvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 23:09:04 by syndraum          #+#    #+#             */
/*   Updated: 2019/11/15 17:34:20 by roalvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_conv	*creat_conv(char **cursor, va_list *l_arg)
{
	t_conv	*conv;

	(*cursor)++;
	if (*cursor == NULL)
		return (NULL);
	if (!(conv = malloc(sizeof(t_conv))))
		return (NULL);
	conv->flag = creat_flags(cursor);
	set_widht(conv, cursor, l_arg);
	set_precision(conv, cursor, l_arg);
	conv->lenght = get_lenght(*cursor);
	if (!(conv->type = get_type(**cursor)))
		return (NULL);
	(*cursor)++;
	set_content(conv, l_arg);
	return (conv);
}

t_list	*creat_flags(char **str)
{
	t_list	*l_flag;
	t_flag	*flag;

	l_flag = NULL;
	flag = NULL;
	while (get_flag(**str) != 0)
	{
		if (!(flag = malloc(sizeof(t_flag))))
		{
			ft_lstclear(&l_flag, &free_content);
			return (NULL);
		}
		*flag = get_flag(**str);
		ft_lstadd_back(&l_flag, ft_lstnew(flag));
		(*str)++;
	}
	return (l_flag);
}

void	set_widht(t_conv *conv, char **str, va_list *l_arg)
{
	if (**str == '*')
	{
		conv->width = va_arg(*l_arg, int);
		if (conv->width < 0)
		{
			set_flag(conv, MINUS);
			conv->width = ft_abs(conv->width);
		}
		(*str)++;
	}
	else if (ft_isdigit(**str))
	{
		conv->width = ft_atoi(*str);
		while (ft_isdigit(**str))
			(*str)++;
	}
	else
		conv->width = -1;
}

void	set_precision(t_conv *conv, char **str, va_list *l_arg)
{
	if (**str == '.')
	{
		(*str)++;
		if (**str == '*')
		{
			conv->precision = va_arg(*l_arg, int);
			(*str)++;
		}
		else if (ft_isdigit(**str))
		{
			conv->precision = ft_atoi(*str);
			while (ft_isdigit(**str))
				(*str)++;
		}
		else
			conv->precision = 0;
	}
	else
		conv->precision = -1;
}

void	set_content(t_conv *conv, va_list *l_arg)
{
	if (conv->type == STRING)
		conv->content = get_string(l_arg);
	else if (conv->type == CHARACTER)
		conv->content = get_char(l_arg);
	else if (is_int(conv->type))
		conv->content = get_int(l_arg);
	else if (is_uint(conv->type))
		conv->content = get_uint(l_arg);
	else if (conv->type == POINTEUR)
		conv->content = get_ulong(l_arg);
	else
		conv->content = NULL;
}
