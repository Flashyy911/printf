/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbai-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 23:09:22 by asbai-el          #+#    #+#             */
/*   Updated: 2020/01/22 23:09:26 by asbai-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_percent(t_flags *f)
{
	int		cnt;
	char	c;

	cnt = 0;
	c = '%';
	if (f->point == 0)
		cnt += put_car(c, f);
	else
	{
		if (f->precision_len == 0)
		{
			if (f->width == 0)
				cnt += write(1, &c, 1);
			else
				cnt += put_car(c, f);
		}
		else
			cnt += put_car(c, f);
	}
	return (cnt);
}
