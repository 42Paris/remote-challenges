/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:16:47 by memartin          #+#    #+#             */
/*   Updated: 2020/04/23 20:24:53 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>
# include <inttypes.h>
# include <fcntl.h>
# include <string.h>
# include <limits.h>
# include <ctype.h>

# define BUFF_SIZE_GNL 32

typedef struct		s_print
{
	char			*fmt;
	char			result[4000];
	size_t			size;
	size_t			buff_i;
	size_t			fmt_i;
	char			conv;
	int				f_hash;
	int				f_zero;
	int				f_moins;
	int				f_plus;
	int				f_space;
	int				m_h;
	int				m_hh;
	int				m_l;
	int				m_ll;
	int				m_j;
	int				m_z;
	int				n_neg;
	int				precision;
	int				width;
	int				dot;
	int				f_pre;
	int				neg_pre;
	va_list			arg;
}					t_print;

int					ft_printf(const char *fmt, ...);
void				ft_printf_buffer(t_print *p);
void				ft_printf_add_char(t_print *p, const char *fmt);
void				ft_printf_parse(t_print *p, const char *fmt);
void				ft_printf_conv(t_print *p);
void				ft_printf_di(t_print *p);
void				ft_printf_oux(t_print *p);
void				ft_printf_c(t_print *p);
void				ft_printf_s(t_print *p);
void				ft_printf_modulo(t_print *p);
void				ft_printf_p(t_print *p);
void				ft_printf_flags(t_print *p, char *s, char *prefix);
void				ft_printf_add_conv(t_print *p, char *s);
char				*ft_ltoa(intmax_t n);
char				*ft_utoa_base(unsigned long long n, int base);
char				*ft_joinfree(char *s1, char *s2);
char				*ft_strjoin(const char *s1, const char *s2);
void				ft_strdel(char **as);
size_t				ft_intmaxsize(intmax_t n);
char				*ft_strnew(size_t size);
void				ft_putchar(char c);
char				*ft_strdup(const char *s);
size_t				ft_strlen(const char *s);
void				*ft_memset(void *s, int c, size_t l);
int					ft_isdigit(int c);
int					ft_atoi(const char *s);
char				*ft_strchr(const char *s, int c);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strcpy(char *dest, const char *src);
int					ft_isspace(int c);
void				ft_putendl(const char *s);
void				ft_putstr(const char *s);
void				ft_printf_majd(t_print *p);
void				ft_printf_majo(t_print *p);
void				ft_printf_maju(t_print *p);
void				ft_printf_majc(t_print *p);
void				ft_printf_majs(t_print *p);
int					ft_printf_unicode(unsigned char *buff, int c);
void				ft_printf_precision(t_print *p, const char *fmt);
void				ft_printf_precision_star(t_print *p, const char *fmt);
int					get_next_line(const int fd, char **line);
char				*ft_substr(const char *s, unsigned int start, size_t len);
size_t				ft_intsize(intmax_t n);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strallocset(char c, size_t size);
void				ft_bzero(void *s, size_t n);

#endif
