/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbai-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 23:10:54 by asbai-el          #+#    #+#             */
/*   Updated: 2020/01/22 23:10:57 by asbai-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_str(char *str, t_flags *f)
{
	int	cnt;

	cnt = 0;
	if (f->flags == 'q')
		cnt += write_space(f->width - ft_strlen(str));
	if (f->flags == '0')
		cnt += write_zero(f->width - ft_strlen(str));
	cnt += write(1, str, ft_strlen(str));
	if (f->flags == '-')
		cnt += write_space(f->width - ft_strlen(str));
	return (cnt);
}

int	put_strp(char *str, t_flags *f)
{
	int	cnt;
	int	len;

	cnt = 0;
	len = (f->precision_len > ft_strlen(str)) ? ft_strlen(str)
		: f->precision_len;
	if (f->flags == 'q' && f->width > len)
		cnt += write_space(f->width - len);
	if (f->flags == '0' && f->width > len)
		cnt += write_zero(f->width - len);
	cnt += ft_putnstr(str, len);
	if (f->flags == '-' && f->width > len)
		cnt += write_space(f->width - len);
	return (cnt);
}

int	print_string(t_flags *f, va_list p)
{
	int		cnt;
	char	*str;

	cnt = 0;
	str = va_arg(p, char*);
	if (str == NULL)
		str = "(null)";
	if (f->point == 0)
		cnt += put_str(str, f);
	else
	{
		if (f->precision_len == 0)
		{
			if (f->width != 0)
			{
				if (f->flags == '0')
					cnt += write_zero(f->width);
				else
					cnt += write_space(f->width);
			}
		}
		else
			cnt += put_strp(str, f);
	}
	return (cnt);
}
