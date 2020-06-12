/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 03:56:23 by juligonz          #+#    #+#             */
/*   Updated: 2019/08/15 12:50:13 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		print_ascii_line(unsigned char *s, int size)
{
	int i;

	i = 0;
	ft_putchar(' ');
	while (i < size)
	{
		if (s[i] >= 32 && s[i] <= 126)
			ft_putchar(s[i]);
		else
			ft_putchar('.');
		i++;
	}
	ft_putchar('\n');
}

static void		ft_putnbr_hex(unsigned long nb, int size)
{
	char	c;

	if (size == 0)
		return ;
	ft_putnbr_hex(nb / 16, size - 1);
	c = nb % 16 + '0';
	if (c > '9')
		c += 39;
	ft_putchar(c);
}

static void		end_ascii(unsigned int size, unsigned char *p_str)
{
	unsigned int	nb_spaces;

	nb_spaces = 41 - ((size % 16 * 2) + size % 16 / 2);
	nb_spaces = (size % 16) % 2 ? nb_spaces - 1 : nb_spaces;
	while (--nb_spaces > 0 && size % 16 != 0)
		ft_putchar(' ');
	print_ascii_line(p_str, (size % 16 && size != 16 ? size % 16 : 16));
}

void			*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned char	*p_str;
	unsigned char	*str;

	if (!addr || !size)
		return (addr);
	i = -1;
	p_str = 0;
	str = (unsigned char *)addr;
	while (++i < size)
	{
		if (i % 16 == 0)
		{
			if (i != 0)
				print_ascii_line(p_str, 16);
			p_str = (unsigned char *)&str[i];
			ft_putnbr_hex((unsigned long)&str[i], 15);
			ft_putchar(':');
		}
		if (i % 2 == 0)
			ft_putchar(' ');
		ft_putnbr_hex((unsigned long)str[i], 2);
	}
	end_ascii(size, p_str);
	return (addr);
}
