/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 15:33:55 by hbaudet           #+#    #+#             */
/*   Updated: 2020/01/03 11:50:16 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

typedef unsigned int	t_uint;

int				ft_printf(const char *fmt, ...);
int				ft_putnbr_printf(long long n, int fd, t_uint *f);
int				ft_convert_arg(const char *str, va_list ap, int *i);
int				ft_convert_char(unsigned char c, t_uint *f);
int				ft_convert_string(char *str, t_uint *f);
int				ft_convert_ptr(void *ptr, t_uint *f);
int				ft_convert_int(int nb, t_uint *f);
int				ft_convert_unsigned(t_uint nb, t_uint *f);
int				ft_conv_hex(t_uint p, t_uint *f, char x);
void			ft_arg_0(t_uint *f, const char *av, va_list ap, int *ind);
void			ft_dot(t_uint *f, const char *av, va_list ap, int *ind);
void			ft_arg_star(t_uint *f, va_list ap, int *ind);
void			ft_arg_minus(t_uint *f, int *ind);
void			ft_arg_num(t_uint *f, const char *av, int *ind);
int				ft_bzero_printf(void *s, size_t n, int b);
void			ft_fill_ptr(long long p, t_uint *i, char *buff, char x);
int				ft_write_hexa(t_uint *f, char *buff, t_uint *i);
t_uint			ft_write_hexa_null(t_uint *f);
int				ft_hex(char *buff, t_uint *i, t_uint p, t_uint *f);
int				int_neg(int nb, t_uint *f);
void			ft_flags(t_uint *f, const char *av, va_list ap, int *i);

#endif
