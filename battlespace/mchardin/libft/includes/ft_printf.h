/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <mchardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 09:53:01 by mchardin          #+#    #+#             */
/*   Updated: 2020/02/01 18:20:16 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include "libft_structs.h"

int				ft_printf(const char *str, ...);
int				ft_dprintf(int fd, const char *str, ...);
char			*ft_sprintf(const char *str, ...);
char			*ft_char_to_str(char c, char *cz);
int				ft_len_c(const char *s, int c);
void			ft_delcontent(void *str);
int				ft_print_lst(int fd, t_list *lst);
int				ft_isconv(char c);
int				ft_flagsize(const char *s, int *i, va_list *ap, t_flags *conv);
int				ft_addflags(t_flags *conv, const char *s, int *i, va_list *ap);
int				ft_analyse_nb(int nb, char chr, t_flags *conv);
char			*ft_conversion(char *to_conv, t_flags *conv, char c);
char			*ft_fill_z(char *str, int z, char c);
char			*ft_fill_sp(char *str, int sp_b, int sp_a);
char			*ft_fill_p(char *to_conv, t_flags *conv, char c);
char			*ft_unsign_hexa(int nb, char chr);
char			*ft_convert_hexa(uintptr_t nb, char *base_to);
int				ft_atoi_base(char *str, char *base);
int				check_b(char *base);
char			*ft_itoa_un(uintptr_t n);
char			*ft_point(uintptr_t nb);
char			*ft_convert_string(char *to_conv, t_flags *conv, char c);
char			*ft_fill_pre(char *str, t_flags *conv, char c);
t_cont			*ft_strct(char *str, char czero);
int				ft_str(const char *str, t_list **lst, va_list *ap);
char			*ft_arg(const char *str, va_list *ap, int *i, char *cz);
char			*ft_flag(const char *str, va_list *ap, int *i, char *cz);
char			*ft_noflag(const char chr, va_list *ap, char *cz);

#endif
