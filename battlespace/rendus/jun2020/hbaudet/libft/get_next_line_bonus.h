/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 11:54:21 by hbaudet           #+#    #+#             */
/*   Updated: 2020/01/14 21:33:53 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

typedef unsigned int	t_uint;

typedef struct		s_b
{
	char			buff[BUFFER_SIZE >= 0 ? BUFFER_SIZE : 0];
	int				filedesc;
	int				i;
	int				ret;
	struct s_b		*next;
}					t_buff;

int					get_next_line_part_two(char **line, t_buff *lst);
t_buff				*ft_lstnew_gnl(int fd);
int					get_next_line(int fd, char **line);
char				*ft_strjoin_gnl(char const *s1, char const *s2,
	int s, int e);
char				*ft_strncpy_gnl(char *dest, const char *src, size_t n);
int					ft_join_and_update(t_buff *lst, char **ptr, unsigned int x);
int					ft_error(char **ptr);
size_t				ft_strlen(const char *s);

#endif
