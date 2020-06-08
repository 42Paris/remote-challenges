/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   date.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 18:52:58 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/27 10:18:53 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long
	days_to_year(long long *days)
{
	long	year;
	long	nb;

	year = 1970;
	while (*days >= (nb = ((year % 4 == 0) && (year % 100 != 0) ? 366 : 365)))
	{
		*days -= nb;
		++year;
	}
	return (year);
}

static t_date
	*sec_to_date(long long second, t_date *date)
{
	static const long	days_in_month[2][12] = {
		{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
		{ 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
	};
	long long			days;
	long				nb;
	int					bix;

	days = second / 86400;
	date->sec = second % 86400 % 60;
	date->min = second % 86400 % 3600 / 60;
	date->hour = second % 86400 / 3600;
	date->year = days_to_year(&days);
	date->month = 0;
	bix = (date->year % 4 == 0) && (date->year % 100 != 0);
	while (days >= (nb = days_in_month[bix][date->month]))
	{
		days -= nb;
		++date->month;
	}
	date->day = days + 1;
	return (date);
}

static void
	long_to_date(t_conv *c, t_date *date)
{
	static const char	*months[12] = {
		"Janvier", "Février", "Mars", "Avril",
		"Mai", "Juin", "Juillet", "Août",
		"Septembre", "Octobre", "Novembre", "Décembre"};

	itoa_base(c, date->day, 10, 0);
	bwrite(&c->conv, " ", 1);
	bwrite(&c->conv, months[date->month], ft_strlen(months[date->month]));
	bwrite(&c->conv, " ", 1);
	itoa_base(c, date->year, 10, 0);
}

static void
	long_to_time(t_conv *c, t_date *date)
{
	if (date->hour < 10)
		bwrite(&c->conv, "0", 1);
	itoa_base(c, date->hour, 10, 0);
	bwrite(&c->conv, ":", 1);
	if (date->min < 10)
		bwrite(&c->conv, "0", 1);
	itoa_base(c, date->min, 10, 0);
	bwrite(&c->conv, ":", 1);
	if (date->sec < 10)
		bwrite(&c->conv, "0", 1);
	itoa_base(c, date->sec, 10, 0);
}

int	convert_k(t_printf *pf, t_formatter *fmt, va_list ap)
{
	long long	arg;
	t_date		date;
	t_conv		c;

	ft_bzero(&c, sizeof(t_buffer));
	arg = va_arg(ap, long long);
	if (fmt->precision == 1)
		long_to_time(&c, sec_to_date(arg, &date));
	else if (fmt->precision >= 2)
	{
		long_to_date(&c, sec_to_date(arg, &date));
		bwrite(&c.conv, "  ", 2);
		long_to_time(&c, sec_to_date(arg, &date));
	}
	else
		long_to_date(&c, sec_to_date(arg, &date));
	pf->len += put(c.conv.buff, c.conv.len);
	return (1);
}
