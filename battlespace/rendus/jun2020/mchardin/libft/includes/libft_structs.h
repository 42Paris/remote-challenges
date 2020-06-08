/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <mchardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 13:44:07 by mchardin          #+#    #+#             */
/*   Updated: 2020/04/22 22:28:27 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_STRUCTS_H
# define LIBFT_STRUCTS_H

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef	struct	s_flags
{
	char	flaglist[3];
	int		size;
	int		precision;
}				t_flags;

typedef	struct	s_cont
{
	char	*str;
	char	czero;
}				t_cont;

#endif
