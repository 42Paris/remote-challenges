/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <roalvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 17:47:56 by roalvare          #+#    #+#             */
/*   Updated: 2020/05/01 19:09:36 by roalvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>

typedef enum	e_type
{
	CHARACTER = 'c',
	STRING = 's',
	POINTEUR = 'p',
	INT = 'i',
	DECIMAL = 'd',
	UNSIGNED = 'u',
	HEXA_L = 'x',
	HEXA_U = 'X',
	POURCENT = '%',
}				t_type;

typedef enum	e_flag
{
	MINUS = '-',
	ZERO = '0',
	PLUS = '+',
	HASH = '#',
	SPACE = ' '
}				t_flag;

typedef	enum	e_lenght
{
	NOTHING,
	CHAR,
	SHORT,
	LONG,
	LONG_LONG
}				t_lenght;

typedef struct	s_conv
{
	t_list		*flag;
	int			width;
	int			precision;
	t_lenght	lenght;
	t_type		type;
	void		*content;
}				t_conv;

typedef struct	s_node
{
	char	*str;
	int		len;
}				t_node;

t_flag			get_flag(char c);
t_type			get_type(char c);
t_lenght		get_lenght(char *s);

t_conv			*creat_conv(char **cursor, va_list *l_arg);
t_list			*creat_flags(char **str);
void			set_widht(t_conv *conv, char **str, va_list *l_argv);
void			set_precision(t_conv *conv, char **str, va_list *l_arg);
void			set_content(t_conv *conv, va_list *l_arg);

char			has_flag(t_list *l_flag, t_flag flag);
char			has_sign(t_list *lst);
int				is_int(t_type type);
int				is_uint(t_type type);

unsigned char	*get_char(va_list *l_arg);
char			*get_string(va_list *l_arg);
int				*get_int(va_list *l_arg);
unsigned int	*get_uint(va_list *l_arg);
unsigned long	*get_ulong(va_list *l_arg);

void			free_content(void *content);
void			free_conv(void *content);
void			free_node(void *content);
void			*free_content_r(void *content);
void			*free_node_r(void *content);

t_node			*ft_newnode(char *str, int len);
t_list			*create_node(char *str, int len);

t_list			*get_list(char	*str, va_list *l_arg);
t_list			*get_convert(t_conv *conv);

int				lstc_size(t_list *lst);
t_list			*s_in_lst(char *str, t_conv *conv);
char			*lst_to_s(t_list *lst);
t_list			*add_indlst(t_list **lst, void *content, int index);

void			*set_padding(t_list *lst, t_conv *conv);
void			reset_s(t_list *lst);
t_list			*pad_zero(t_list *lst, int len);
void			set_flag(t_conv *conv, t_flag f);

t_list			*c_int(t_conv *conv);
t_list			*c_uint(t_conv *conv);
t_list			*c_pointer(t_conv *conv);
char			*ft_utoa(unsigned long nbr, char *base);

t_list			*c_char(t_conv *conv);
t_list			*c_pourcent(void);

void			ft_putstr_n(char *str, int n);
int				ft_printf(const char *str, ...);

#endif
