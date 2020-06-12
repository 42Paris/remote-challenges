/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 15:28:25 by juligonz          #+#    #+#             */
/*   Updated: 2019/12/13 17:57:51 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flush_buffer(t_manager *p)
{
	if (p->caller == PRINTF || p->caller == DPRINTF)
		write(p->fd, p->buffer, p->buffer_idx);
	else if (p->caller == SPRINTF)
	{
		ft_strncpy(p->dst + p->dst_len, p->buffer, p->buffer_idx);
		p->dst_len += BUFFER_SIZE;
	}
	else if (p->caller == ASPRINTF && !p->malloc_fail)
	{
		p->dst = ft_strdup_cat(p->dst, p->buffer, p->dst_len, p->buffer_idx);
		if (!p->dst)
			p->malloc_fail = 1;
		p->dst_len += BUFFER_SIZE;
	}
	p->buffer_idx = 0;
}

void	write_buffer(t_manager *p, void *s, size_t n)
{
	int i;

	i = 0;
	while (n--)
	{
		if (p->buffer_idx == BUFFER_SIZE)
			flush_buffer(p);
		p->buffer[p->buffer_idx++] = ((char *)s)[i++];
		p->len++;
	}
}

void	write_buffer_wcs(t_manager *p, wchar_t *s, size_t n)
{
	int i;

	i = 0;
	while (n--)
	{
		if (p->buffer_idx == BUFFER_SIZE)
			flush_buffer(p);
		p->buffer[p->buffer_idx++] = (char)s[i++];
		p->len++;
	}
}
