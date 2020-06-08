/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_lib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <mchardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:01:41 by mchardin          #+#    #+#             */
/*   Updated: 2020/03/02 17:51:36 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEW_LIB_H
# define NEW_LIB_H

# include <string.h>

char			*ft_strdup_no_sp(char *src);
char			**ft_strs_plus_one(char **strs, char *add);
void			ft_free_strs(char ***grid);
size_t			ft_strslen(char **s);
char			**ft_strs_cpy(char **strs);
int				ft_iswhitespace(char c);
char			*ft_strndup(char *src, int len);
char			**ft_strs_add_end(char **strs, char *add, int end);
void			ft_freez(void **elem);

#endif
