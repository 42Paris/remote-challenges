/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 17:58:50 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/27 10:50:35 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>
# include <stdint.h>
# include <stddef.h>

# define PTF_BUFF_SIZE 10

# define CONVERTERS		"diDoOuUxXcCsSpbnqQkmrf"
# define NUMERICS		"diDoOuUxXpbf"
# define LONG_NUMERICS	"DOU"
# define LENGTHS		"hhlljtzL"
# define FLAGS			"0+- #'"

# define ERROR_MESSAGE "Error"

typedef struct	s_buffer
{
	char	buff[5000];
	size_t	len;
}				t_buffer;

typedef struct	s_double
{
	unsigned char	*m;
	unsigned char	buff[10000];
	int				sign;
	int				expo;
	unsigned long	mant;
	int				beg;
	char			prefix;
}				t_double;

typedef struct	s_conv
{
	char		*str;
	t_buffer	conv;
	t_buffer	prec;
	t_buffer	width;
	t_buffer	prefix;
	char		sign;
	int			dbl;
}				t_conv;

typedef struct	s_arglist
{
	va_list	begin;
	va_list	natural;
	va_list	selected;
}				t_arglist;

typedef struct	s_printf
{
	t_arglist	args;
	size_t		len;
	char		*format;
	char		*next;
}				t_printf;

typedef struct	s_formatter
{
	char	length;
	char	flags;
	int		width;
	int		precision;
	int		pos;
	char	converter;
	int		index;
	int		prev_len;
}				t_formatter;

typedef struct	s_date
{
	long	year;
	long	month;
	long	day;
	long	hour;
	long	min;
	long	sec;
}				t_date;

int				fill_precision(t_conv *c, t_formatter *fmt);
void			fill_width(t_conv *c, t_formatter *fmt);
void			fill_width_chr(t_printf *pf, t_formatter *fmt, int conv_ret);
int				convert(t_printf *pf, t_formatter *fmt);
int				convert_char(t_printf *pf, t_formatter *fmt, va_list ap);
int				convert_wchar(t_printf *pf, t_formatter *fmt, va_list ap);
int				convert_const(t_printf *pf, t_formatter *fmt);
int				convert_q(t_printf *pf, t_formatter *fmt, va_list ap);
int				convert_q_up(t_printf *pf, t_formatter *fmt, va_list ap);
int				convert_k(t_printf *pf, t_formatter *fmt, va_list ap);
void			compute_f(t_double *d);
void			fill_dbl(t_double *d);
int				convert_f(t_printf *pf, t_formatter *fmt, va_list ap);
void			write_conv(t_conv *c, t_double *d, t_formatter *fmt);
int				write_double(t_printf *pf, t_formatter *fmt, t_double *d);
int				convert_di(t_printf *pf, t_formatter *fmt, va_list ap);
int				convert_u(t_printf *pf, t_formatter *fmt, va_list ap);
int				convert_x(t_printf *pf, t_formatter *fmt, va_list ap);
int				convert_o(t_printf *pf, t_formatter *fmt, va_list ap);
int				convert_b(t_printf *pf, t_formatter *fmt, va_list ap);
int				convert_n(t_printf *pf, t_formatter *fmt, va_list ap);
int				set_coma(t_conv *c, int len);
int				itoa_base(t_conv *c, intmax_t i, int base, char upcase);
int				signed_integer(t_formatter *fmt, t_conv *c, va_list ap, int b);
int				unsigned_integer(t_formatter *fmt, t_conv *c, va_list ap,
																		int b);
int				convert_m(t_printf *pf, t_formatter *fmt, va_list ap);
int				convert_r(t_printf *pf, t_formatter *fmt, va_list ap);
int				convert_p(t_printf *pf, t_formatter *fmt, va_list ap);
int				convert_str(t_printf *pf, t_formatter *fmt, va_list ap);
int				convert_wstr(t_printf *pf, t_formatter *fmt, va_list ap);
void			parse_formatter(t_formatter *fmt, t_printf *pf);
int				ft_printf(const char *format, ...);
void			get_arg_at(int pos, t_arglist *args);
int				handle_formatter(t_printf *pf);
int				ft_vprintf(const char *format, va_list ap);
long double		ft_ldabs(long double d);
void			str_power(unsigned char *p, long a, int b, int len);
void			str_add(unsigned char *a, unsigned char *b, int len);
void			str_multi(unsigned char *a, int b, int len);
void			str_divi(unsigned char *a, int b, int len);
void			str_divi_2(unsigned char *a, int len);
int				is_length(char c, t_formatter fmt, int v);
int				is_flag(char c, t_formatter fmt);
char			*walk_format(char *s, int c);
size_t			wchartoa(char *s, wint_t w);
size_t			wstrtoa(char *s, const wchar_t *wstr);
size_t			wstrntoa(char *s, const wchar_t *wstr, size_t n);
int				check_unicode(wint_t *c);
void			print(char *s, int size);
int				put(char *s, int len);
size_t			bwrite(t_buffer *b, const char *s, size_t len);
size_t			dblwrite(t_buffer *b, unsigned char *s, size_t len);

#endif
