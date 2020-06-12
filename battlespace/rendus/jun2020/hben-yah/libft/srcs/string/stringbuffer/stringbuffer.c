/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringbuffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 18:12:20 by hben-yah          #+#    #+#             */
/*   Updated: 2019/02/11 15:35:17 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		sb_add(t_strbuffer *sb, const char *data, size_t len)
{
	if (!sb_check_free_space(sb, len))
		return (0);
	ft_memcpy(sb->str + sb->length, data, len);
	sb->length += len;
	return (1);
}

int		sb_check_free_space(t_strbuffer *sb, size_t len)
{
	size_t	length;
	size_t	new_len;

	length = sb->length + len;
	if (length > sb->max_len)
	{
		new_len = (sb->max_len == 0 ? STRINGBUFFER_SIZE : sb->max_len);
		while (new_len < length)
			new_len *= 2;
		return (sb_remalloc(sb, new_len));
	}
	return (1);
}

int		sb_remalloc(t_strbuffer *sb, size_t new_len)
{
	if (sb->length > new_len)
		sb->length = new_len;
	sb->max_len = new_len;
	sb->str[sb->length] = 0;
	if (!(sb->str = ft_strrealloc(sb->str, new_len)))
		return (0);
	return (1);
}

int		sb_slide(t_strbuffer *sb, size_t bef, size_t aft)
{
	const size_t	len = aft - bef;
	t_strbuffer		tmp;

	if (len > 0)
	{
		ft_bzero((void *)&tmp, sizeof(t_strbuffer));
		if (!sb_check_free_space(&tmp, len))
			return (0);
		ft_memcpy(tmp.str, sb->str + bef, len);
		ft_memmove(sb->str + bef, sb->str + aft, sb->length - aft);
		ft_memcpy(sb->str + sb->length - len, tmp.str, len);
		free(tmp.str);
	}
	return (1);
}

int		sb_init(t_strbuffer *sb)
{
	ft_bzero((void *)sb, sizeof(t_strbuffer));
	return (sb_check_free_space(sb, STRINGBUFFER_SIZE));
}
