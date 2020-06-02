/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <roalvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:47:32 by roalvare          #+#    #+#             */
/*   Updated: 2020/06/02 09:02:46 by roalvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct	s_file
{
	int				fd;
	char			buf[BUFFER_SIZE + 1];
	char			*crs;
	struct s_file	*next;
}				t_file;

typedef struct		s_listc
{
	char			content;
	struct s_listc	*next;
}					t_listc;


int				get_next_line(int fd, char **line);
t_listc			*line_to_list(t_file *f, int *brk, int *count);
void			*list_to_str(t_listc *list, char **line, int len);
int				ft_lstnew_back(t_listc **alst, char c);
void			*free_list(t_listc *list);
t_file			*get_file(int fd, t_file **file);
int				del_file(int fd, t_file **file);

#endif
