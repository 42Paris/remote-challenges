/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:53:56 by juligonz          #+#    #+#             */
/*   Updated: 2020/01/31 15:46:31 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <wchar.h>
# include <float.h>
# include "libft.h"

# define BUFFER_SIZE 64

enum	e_printf{PRINTF, DPRINTF, SPRINTF, ASPRINTF};

typedef struct	s_flags
{
	uint16_t	dash:1;
	uint16_t	zero:1;
	uint16_t	dot:1;
	uint16_t	star:1;
	uint16_t	l:1;
	uint16_t	ll:1;
	uint16_t	h:1;
	uint16_t	hh:1;
	uint16_t	j:1;
	uint16_t	apostrophe:1;
	uint16_t	hash:1;
	uint16_t	space:1;
	uint16_t	plus:1;
	uint16_t	l_uppercase:1;
	uint16_t	remain_bits:2;
}				t_flags;

typedef struct	s_manager
{
	int				fd;
	t_flags			f;
	int				width;
	int				len;
	int				precision;
	char			specifier;
	char			buffer[BUFFER_SIZE];
	int				buffer_idx;
	enum e_printf	caller;
	char			*dst;
	int				dst_len;
	int8_t			malloc_fail;
	int8_t			is_error;
}				t_manager;

typedef void	(*t_handler)(va_list args, t_manager *p);

/*
** ***************** conversions ******************
*/

void			conv_c(va_list args, t_manager *p);
void			conv_s(va_list args, t_manager *p);
void			conv_p(va_list args, t_manager *p);
void			conv_d(va_list args, t_manager *p);
void			conv_i(va_list args, t_manager *p);
void			conv_u(va_list args, t_manager *p);
void			conv_x_lowcase(va_list args, t_manager *p);
void			conv_x_upcase(va_list args, t_manager *p);
void			conv_n(va_list args, t_manager *p);
void			conv_f(va_list args, t_manager *p);
void			conv_g(va_list args, t_manager *p);
void			conv_e(va_list args, t_manager *p);
void			conv_o(va_list args, t_manager *p);
void			conv_mod(va_list args, t_manager *p);

/*
** **************** print in buffer ****************
*/

void			put_int(int64_t n, t_manager *p);
void			put_uint(uint64_t n, t_manager *p);
void			put_hex(uint64_t n, t_manager *p);
void			put_ptr(uint64_t n, t_manager *p);
void			put_oct(int64_t n, t_manager *p);
void			put_f(long double n, t_manager *p);
void			put_g(long double n, t_manager *p);
void			put_e(long double n, t_manager *p);

/*
** ***************** floats utils ******************
*/

void			put_double(long double n, t_manager *p);
void			put_double_width(t_manager *p, int nb_char);
void			put_double_zero(t_manager *p, int nb_char);
int				trailing_zero(long double mantis, int precision);
int				is_valid_float(long double n, t_manager *p);

/*
** **************** Lenght modifier ****************
*/

int64_t			cast_signed(t_manager *p, va_list args);
uint64_t		cast_unsigned(t_manager *p, va_list args);
void			*cast_ptr(t_manager *p, va_list args);
wint_t			cast_c(t_manager *p, va_list args);
wchar_t			*cast_s(t_manager *p, va_list args);

/*
** ******************* Utility  ********************
*/

char			*ft_strdup_cat(char *src, char *buf, int src_len, int buf_len);
void			write_buffer(t_manager *p, void *s, size_t n);
void			write_buffer_wcs(t_manager *p, wchar_t *s, size_t n);
void			flush_buffer(t_manager *p);
int				read_flags(t_manager *p, va_list args, const char *format);
void			parse(va_list args, t_manager *p);

#endif
