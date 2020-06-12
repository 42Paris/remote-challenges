/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_proto.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 20:46:39 by juligonz          #+#    #+#             */
/*   Updated: 2020/01/31 15:50:26 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_PROTO_H
# define PRINTF_PROTO_H

# include <stdarg.h>

int	ft_printf(const char *format, ...) __attribute__((format(printf,1,2)));
int	ft_dprintf(
	int fd, const char *format, ...) __attribute__((format(printf,2,3)));
int	ft_sprintf(
	char *str, const char *format, ...) __attribute__((format(printf,2,3)));
int	ft_asprintf(
	char **ret, const char *format, ...) __attribute__((format(printf,2,3)));

int	ft_vprintf(const char *format, va_list ap);
int	ft_vdprintf(int fd, const char *format, va_list ap);
int	ft_vsprintf(char *dst, const char *format, va_list ap);
int	ft_vasprintf(char **ret, const char *format, va_list ap);

#endif
