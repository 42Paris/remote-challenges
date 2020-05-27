/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 11:54:21 by hbaudet           #+#    #+#             */
/*   Updated: 2019/12/11 16:41:26 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 99
# endif
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

typedef unsigned int t_uint;

int		get_next_line(int fd, char **line);
char	*ft_strjoin_gnl(char const *s1, char const *s2, t_uint n);
char	*ft_strncpy_gnl(char *dest, const char *src, size_t n);
int		ft_join_and_update(char *buff, int start, char **ptr);
int		ft_error(char **ptr);

#endif
